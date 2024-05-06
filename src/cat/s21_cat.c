#include "s21_cat.h"

int main(int argc, char *argv[]) { return start_program(argc, argv); }

int start_program(int argc, char *argv[]) {
  int count_errors = 1;
  char line[MAX_LINES];

  flag_options flag = {.b = 0, .e = 0, .n = 0, .s = 0, .t = 0, .v = 0};

  count_errors = parser_flags(argc, argv, &flag);

  if (flag.b == 1) {
    flag.n = 0;
  } else if (flag.n == 1) {
    flag.b = 0;
  }

  if (argc == 1) {
    only_cat();
  } else if (argc >= 2 && flag.b == 0 && flag.e == 0 && flag.n == 0 &&
             flag.s == 0 && flag.t == 0 && flag.v == 0) {
    for (int i = optind; i < argc; i++) {
      open_and_print_file(argv[i], line);
    }
  } else if (argc > 2) {
    for (int i = optind; i < argc; i++) {
      open_and_print_file_with_flags(argv[i], line, &flag);
    }
  }

  return count_errors;
}

int open_and_print_file(char *filename, char *line) {
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("n/a");
    return -1;
  }

  while (fgets(line, MAX_LINES, file) != NULL) {
    printf("%s", line);
  }

  fclose(file);
  return 0;
}

int parser_flags(int argc, char *argv[], flag_options *flag) {
  int fail = 0;
  char c;
  while ((c = getopt(argc, argv, "bEnsTvet")) != -1) {
    switch (c) {
      case 'b':
        flag->b = 1;
        break;
      case 'E':
        flag->e = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 'T':
        flag->t = 1;
        break;
      case 'v':
        flag->v = 1;
        break;
      case 'e':
        flag->e = 1;
        flag->v = 1;
        break;
      case 't':
        flag->t = 1;
        flag->v = 1;
        break;
      case '?':
        fail = -1;
        break;
    }
  }
  return fail;
}

int open_and_print_file_with_flags(char *filename, char *line,
                                   flag_options *flag) {
  int str_count = 1;
  FILE *file = fopen(filename, "r");

  if (file == NULL) {
    printf("n/a");
    return -1;
  }

  while (fgets(line, MAX_LINES, file) != NULL) {
    print_line_with_flags(line, flag, &str_count);
  }

  fclose(file);
  return 0;
}

void only_cat() {
  char text[MAX_LINES];
  while (scanf("%c", text) != EOF) {
    printf("%s", text);
  }
}

void print_line_with_flags(char *line, flag_options *flag, int *str_count) {
  int last_sym = '\n';

  for (int i = 0; line[i] != '\0' && i < MAX_LINES; i++) {
    if ((flag->s && line[i] == '\n') && last_sym != '\n') {
    }
    if (((flag->n && flag->b == 0) || (flag->b && line[i] != '\n')) &&
        last_sym == '\n') {
      printf("%6d\t", *str_count);
      *str_count += 1;
    }
    if (flag->t && line[i] == '\t') {
      fputc('^', stdout);
      line[i] = 'I';
    }
    if (flag->e && line[i] == '\n') {
      printf("$");
    }
    if (flag->v) {
      if ((unsigned char)line[i] > 127 && (unsigned char)line[i] < 160)
        printf("M-^");
      if ((line[i] < 32 && line[i] != '\n' && line[i] != '\t') ||
          line[i] == 127)
        printf("^");
      if ((line[i] < 32 || (line[i] > 126 && (unsigned char)line[i] < 160)) &&
          line[i] != '\n' && line[i] != '\t')
        line[i] = line[i] > 126 ? line[i] - 128 + 64 : line[i] + 64;
    } else if (flag->t && line[i] == '\t') {
      printf("^I");
    }

    printf("%c", line[i]);
    last_sym = line[i];
  }
}
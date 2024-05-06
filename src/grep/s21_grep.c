#include "s21_grep.h"

int main(int argc, char *argv[]) { return start_program(argc, argv); }

int start_program(int argc, char *argv[]) {
  int count_errors = 0;
  char pattern[MAX_LINES] = {0};
  struct flags_options flags;

  memset(&flags, 0, sizeof(struct flags_options));

  if (parser_flags(argc, argv, &flags, pattern) != 1 && argc >= 3) {
    count_errors = main_grep(argc, argv, &flags, pattern);
  } else {
    count_errors = -1;
  }

  return count_errors;
}

int main_grep(int argc, char *argv[], struct flags_options *flag,
              char *pattern) {
  char patternL[MAX_LINES] = {0};
  int count_errors = 0;
  int cols = 0;

  if (flag->f != 1 && flag->e != 1)
    snprintf(patternL, MAX_LINES, "%s", argv[optind++]);
  if (flag->f) cols = save_path_file(patternL, pattern);
  if (!flag->f && flag->e) snprintf(patternL, MAX_LINES, "%s", pattern);

  if (cols != -1) {
    int file_c = (argc - optind > 1) ? 1 : 0;

    for (int i = optind; i < argc; i++) {
      if (file_c && !flag->h && !flag->l) printf("%s:", argv[i]);
      count_errors = grep_file(flag, patternL, argv[i]);
    }
  } else {
    count_errors = -1;
  }

  return count_errors;
}

int save_path_file(char *pattern, char *temp) {
  FILE *file = fopen(temp, "r");
  int cols = 0;

  if (file == NULL) {
    cols = -1;
  } else {
    int c = 0;
    while ((c = fgetc(file)) != EOF) {
      if (c == 13 || c == 10) pattern[cols++] = '|';
      if (c != 13 && c != 10) pattern[cols++] = c;
    }
    if (pattern[cols - 1] == '|') pattern[cols - 1] = '\0';
    fclose(file);
  }

  return (cols == -1) ? -1 : (cols + 1);
}

int grep_file(struct flags_options *flag, char *pattern, char *filename) {
  int cflags = (flag->i) ? REG_ICASE | REG_EXTENDED : REG_EXTENDED;
  regex_t regex;
  FILE *file = fopen(filename, "r");
  int count_errors = 0;

  if (file == NULL) {
    count_errors = -1;
  } else {
    regcomp(&regex, pattern, cflags);
    file_work(flag, file, regex, filename);
    regfree(&regex);
    fclose(file);
  }

  return count_errors;
}
int file_work(struct flags_options *flag, FILE *fp, regex_t reg, char *file) {
  char text[MAX_LINES] = {0};
  regmatch_t pmatch[1];
  int line_matches = 0, nline = 1;

  while (fgets(text, MAX_LINES - 1, fp) != NULL) {
    int status = regexec(&reg, text, 1, pmatch, 0);
    int match = 0;

    if (status == 0 && !flag->v) match = 1;
    if (status == REG_NOMATCH && flag->v) match = 1;
    if (match && !flag->l && !flag->c && flag->n) printf("%d:", nline);
    if (match && !flag->l && !flag->c && !flag->o) printf("%s", text);

    if (flag->o && match) {
      for (int i = pmatch[0].rm_so; i < pmatch[0].rm_eo; i++) {
        printf("%c", text[i]);
      }
      printf("\n");
    }
    line_matches += match;
    nline++;
  }

  if (flag->l && line_matches > 0) printf("%s\n", file);
  if (flag->c && !flag->l) printf("%d\n", line_matches);

  return 0;
}
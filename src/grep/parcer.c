#include "s21_grep.h"

int parser_flags(int argc, char *argv[], struct flags_options *flag,
                 char *pattern) {
  int count_errors = 0;
  int i = 0;
  while ((i = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    if (i == 'e') {
      flag->e = 1;
      snprintf(pattern, MAX_LINES, "%s", optarg);
    } else if (i == 'i') {
      flag->i = 1;
    } else if (i == 'v') {
      flag->v = 1;
    } else if (i == 'c') {
      flag->c = 1;
    } else if (i == 'l') {
      flag->l = 1;
    } else if (i == 'n') {
      flag->n = 1;
    } else if (i == 'h') {
      flag->h = 1;
    } else if (i == 's') {
      flag->s = 1;
    } else if (i == 'f') {
      flag->f = 1;
      snprintf(pattern, MAX_LINES, "%s", optarg);
    } else if (i == 'o') {
      flag->o = 1;
    } else {
      count_errors = 1;
    }
  }
  return count_errors;
}
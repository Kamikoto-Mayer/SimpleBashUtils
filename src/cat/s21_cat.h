#ifndef S21_CAT_H
#define S21_CAT_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} flag_options;

int start_program(int argc, char *argv[]);
int open_and_print_file(char *filename, char *line);
int open_and_print_file_with_flags(char *filename, char *line,
                                   flag_options *flag);
void print_line_with_flags(char *line, flag_options *flag, int *str_count);
void only_cat();
int parser_flags(int argc, char *argv[], flag_options *flag);

#endif /* S21_CAT_H */
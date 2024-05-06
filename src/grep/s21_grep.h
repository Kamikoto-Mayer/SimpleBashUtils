#ifndef S21_GREP_H
#define S21_GREP_H

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024

struct flags_options {
  int e;  // Индикатор использования регулярных выражений
  int i;  // Индикатор игнорирования регистра
  int v;  // Индикатор инверсии результатов поиска
  int c;  // Индикатор вывода количества строк
  int l;  // Индикатор вывода имен файлов с совпадениями
  int n;  // Индикатор вывода номеров строк
  int h;  // Индикатор подавления имен файлов в выводе
  int s;  // Индикатор подавления сообщений об ошибках
  int f;  // Индикатор использования файла с шаблоном
  int o;  // Индикатор вывода только совпавших частей строк
};

int start_program(int argc, char *argv[]);
int parser_flags(int argc, char *argv[], struct flags_options *flag,
                 char *pattern);
int main_grep(int argc, char *argv[], struct flags_options *flag,
              char *pattern);
int save_path_file(char *pattern, char *temp);
int grep_file(struct flags_options *flag, char *pattern, char *filename);
int file_work(struct flags_options *flag, FILE *fp, regex_t reg, char *file);

#endif /* S21_GREP_H */
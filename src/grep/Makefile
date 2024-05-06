CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: clean s21_grep

s21_grep: s21_grep.c s21_grep.h parcer.c
	$(CC) $(FLAGS) s21_grep.c parcer.c -o s21_grep

clean:
	@rm -f s21_grep

test: s21_grep
	@bash s21_grep_test.sh
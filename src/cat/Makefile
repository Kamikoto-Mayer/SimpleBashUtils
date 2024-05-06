CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11

all: clean s21_cat

s21_cat: s21_cat.c s21_cat.h
	$(CC) $(FLAGS) s21_cat.c -o s21_cat

clean:
	@rm -f s21_cat

test: s21_cat
	@bash s21_cat_test.sh
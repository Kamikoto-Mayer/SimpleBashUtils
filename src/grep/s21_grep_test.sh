#!/bin/bash

# ./s21_grep for test.txt > test_s21_grep.log
# grep for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -e for test.txt > test_s21_grep.log
# grep -e for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -i for test.txt > test_s21_grep.log
# grep -i for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -v for test.txt > test_s21_grep.log
# grep -v for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -c for test.txt > test_s21_grep.log
# grep -c for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -l for test.txt > test_s21_grep.log
# grep -l for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -n for test.txt > test_s21_grep.log
# grep -n for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -h for test.txt > test_s21_grep.log
# grep -h for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -s for test.txt > test_s21_grep.log
# grep -s for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -o for test.txt > test_s21_grep.log
# grep -o for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

# ./s21_grep -f for test.txt > test_s21_grep.log
# grep -f for test.txt > test_grep.log
# diff -s test_s21_grep.log test_grep.log
# rm -rf test_s21_grep.log test_grep.log

#!/bin/bash

./s21_grep e s21_grep.c > s21_grep.txt
grep e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -e "for" s21_grep.c > s21_grep.txt
grep -e "for" s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -i e s21_grep.c > s21_grep.txt
grep -i e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -v e s21_grep.c > s21_grep.txt
grep -v e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -c e s21_grep.c > s21_grep.txt
grep -c e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -l e s21_grep.c s21_grep.c s21_grep.c > s21_grep.txt
grep -l e s21_grep.c s21_grep.c s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -n e s21_grep.c > s21_grep.txt
grep -n e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -h e s21_grep.c > s21_grep.txt
grep -h e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -s e s21_grep.c > s21_grep.txt
grep -s e s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt

./s21_grep -f pattern s21_grep.c > s21_grep.txt
grep -f pattern s21_grep.c > grep.txt
diff -s s21_grep.txt grep.txt
rm s21_grep.txt grep.txt
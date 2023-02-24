CC = gcc
FLAGS = -Wall -Werror -Wextra -o

strlen_tests :	../build/Quest_1

../build/Quest_1 : s21_string_test.o s21_string.o
	$(CC) -o ../build/Quest_1 s21_string_test.o s21_string.o
s21_string_test.o :
	$(CC) -c $(FLAGS) s21_string_test.o s21_string_test.c
s21_string.o :
	$(CC) -c $(FLAGS) s21_string.o s21_string.c

strcmp_tests :	../build/Quest_2
../build/Quest_2 :	s21_string_test.o s21_string.o

strcpy_tests :	../build/Quest_3
../build/Quest_2 :	s21_string_test.o s21_string.o

strcat_tests :	../build/Quest_4
../build/Quest_2 :	s21_string_test.o s21_string.o

strcmp_tests :	../build/Quest_5
../build/Quest_2 :	s21_string_test.o s21_string.o

strchr_tests :	../build/Quest_6
../build/Quest_2 :	s21_string_test.o s21_string.o

strtok_tests :	../build/Quest_7
../build/Quest_2 :	s21_string_test.o s21_string.o

clean :
	rm s21_string_test.o s21_string.o ../build/Quest_1 ../build/Quest_2 ../build/Quest_3 ../build/Quest_4 ../build/Quest_5 ../build/Quest_6 ../build/Quest_7

rebuild :
	clean
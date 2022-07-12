CC:= gcc
CFLAGS:=-Wall -Werror -Wextra -std=c11 -pedantic
LFLAGS:= $(shell pkg-config --cflags --libs check)
SANITIZER:= #-fsanitize=address
CFLAGS_TEST:= $(SANITIZER) --coverage -c -g 
OBJ_DIR:=obj/
MATH_FUNC:=s21*.c
MATH_OBJ:=s21*.o
MATH_TEST:= math_tests.c

all: s21_math.a test clean cpplint

s21_math.a: clean_lib $(MATH_FUNC)
	$(CC) $(CFLAGS) -c $(MATH_FUNC)
	ar rc s21_math.a $(MATH_OBJ)
	mv *.o obj/
	ranlib 	s21_math.a

test: clean_bin s21_math.a 
	$(CC) $(LFLAGS) s21_math.a $(MATH_TEST) -o test
	- ./test

gcov_report: clean $(MATH_FUNC)
	$(CC) $(CFLAGS_TEST) $(MATH_FUNC)
	ar rc s21_math.a $(MATH_OBJ)
	ranlib 	s21_math.a
	- $(CC) $(LFLAGS) --coverage s21_math.a $(MATH_TEST) -o test
	- ./test
	./../materials/lcov/bin/lcov -f -c --directory . -o ./coverage.info 
	./../materials/lcov/bin/genhtml coverage.info --output-directory=res
	rm -f *.gcda *.gcov *.o *.gcno
	open res/index.html


clean: 
	rm -f *.gcda 
	rm -f *.gcov 
	rm -f *.o 
	rm -f *.gcno 
	rm -f coverage.info

clean_lib:
	rm -f s21_math.a

clean_bin:
		rm -f test

cpplint: ${MATH_FUNC} ${MATH_TEST} *.h
ifeq ("","$(wildcard ./CPPLINT.cfg)")
	cp -f ../materials/linters/CPPLINT.cfg ./CPPLINT.cfg
endif
	!(python3 ../materials/linters/cpplint.py --extensions=c $^ | grep -q :)
	rm -f CPPLINT.cfg
	!(grep '<math.h>' s21*)



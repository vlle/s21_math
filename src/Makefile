CC          := gcc
WARNINGS    := -Wall -Werror -Wextra 
CFLAGS      := -std=c11 -pedantic $(WARNINGS)
INC_CHECK   ?= $(shell pkg-config --cflags check)
LFLAGS      ?= $(shell pkg-config --cflags --libs check) 
TEST_FLAGS  := --coverage -c -g

OBJ_DIR     := obj
TEST_SRC_DIR:= tests_src
TEST_OBJ_DIR:= tests_obj
GCOV_OBJ_DIR:= gcov_res

TEST_SRC  := $(shell find $(TEST_SRC_DIR) -maxdepth 1 -name "*.c")
MATH_SRC  := $(wildcard s21*.c)

TEST_OBJ  := $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRC:.c=.o)))
MATH_OBJ  := $(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(MATH_SRC)))
GCOV_OBJ  := $(addprefix $(GCOV_OBJ_DIR)/, $(patsubst %.c, %.o, $(MATH_SRC)))

MATH_TEST := math_tests.c

all: test 

test: s21_math.a $(TEST_OBJ_DIR)/main.o $(TEST_OBJ)
	$(CC) $(LFLAGS) $(TEST_OBJ) $(TEST_OBJ_DIR)/main.o s21_math.a -o test
	- ./test

s21_math.a: $(MATH_OBJ)
	ar rc s21_math.a $(MATH_OBJ)
	ranlib 	s21_math.a

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $^ -o $@

$(TEST_OBJ_DIR)/main.o: $(MATH_TEST) 
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC)  $(INC_CHECK) -c -o $(TEST_OBJ_DIR)/main.o $(MATH_TEST)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(INC_CHECK) -c $^ -o $@

.PHONY: clean clean_lib clean_bin
clean: 
	rm -f *.gcda 
	rm -f *.gcov 
	rm -f *.gcno 
	rm -f coverage.info
	rm -f test

clean_lib:
	rm -f s21_math.a

clean_bin: 
	rm -f $(MATH_OBJ) 
	rm -f $(TEST_OBJ) 
	rm -f $(GCOV_OBJ) 

rebuild: clean clean_lib clean_bin all


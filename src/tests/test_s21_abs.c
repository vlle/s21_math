#include "../s21_math.h"
#include <stdlib.h>
#include "s21_math_test.h"
#include <check.h>

START_TEST(s21_absClassic) {
    int y = -1;
    int my_ans = s21_abs(y);
    int true_ans;
    true_ans = abs(y);
    ck_assert_int_eq(my_ans, true_ans);
} END_TEST

Suite* abs_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("abs");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_absClassic);
    suite_add_tcase(s, tc_core);

    return s;
}

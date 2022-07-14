#include "../s21_math.h"
#include <check.h>

START_TEST(s21_fabsZero) {
    double y = 0.0;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fabsBig) {
    double y = 123123.1232131231421;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fabsClassic) {
    double y = -1.1232131231421;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

Suite* fabs_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("fabs");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_fabsClassic);
    tcase_add_test(tc_core, s21_fabsZero);
    tcase_add_test(tc_core, s21_fabsBig);
    suite_add_tcase(s, tc_core);

    return s;
}

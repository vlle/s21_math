#include "s21_math_test.h"

START_TEST(s21_acos_too_negative) {
    double x = -12.781;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_acos_negative) {
    double x = -0.67218;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_acos_zero) {
    double x = 1.0;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_acos_positive) {
    double x = 0.4125638719;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST


START_TEST(s21_acos_minusone) {
    double x = -1.0;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_acos_too_positive) {
    double x = 5.64278;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_acosInf) {
    double x = S21_INF;
    long double my_ans = s21_acos(x);
    long double true_ans = acos(x);
    ck_assert_ldouble_nan(true_ans);
    ck_assert_ldouble_nan(my_ans);
} END_TEST

START_TEST(s21_acosNan) {
    int y = S21_NAN;
    long double my_ans = s21_acos(y);
    long double true_ans = acos(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST


Suite* acos_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("acos");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_acos_too_negative);
    tcase_add_test(tc_core, s21_acos_negative);
    tcase_add_test(tc_core, s21_acosNan);
    tcase_add_test(tc_core, s21_acosInf);
    tcase_add_test(tc_core, s21_acos_zero);
    tcase_add_test(tc_core, s21_acos_positive);
    tcase_add_test(tc_core, s21_acos_minusone);
    tcase_add_test(tc_core, s21_acos_too_positive);

    suite_add_tcase(s, tc_core);

    return s;
}


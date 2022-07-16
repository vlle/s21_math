#include "../s21_math.h"
#include <check.h>

START_TEST(s21_logClassic) {
    double x = 3;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_logBig) {
    double x = 3132;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_logLow) {
    double x = -123;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_logZero) {
    double x = 0;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    // ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
    ck_assert_ldouble_infinite(a2);
    ck_assert_ldouble_infinite(b2);
} END_TEST

START_TEST(s21_logNan) {
    double y = S21_NAN;
    long double my_ans = s21_log(y);
    long double true_ans = log(y);
    ck_assert_ldouble_nan(true_ans);
    ck_assert_ldouble_nan(my_ans);
} END_TEST

START_TEST(s21_logInf) {
    double y = S21_INF;
    long double my_ans = s21_log(y);
    long double true_ans = log(y);
    ck_assert(my_ans == true_ans);
} END_TEST

START_TEST(s21_logBelowzero) {
    double x = -2;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    // ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

Suite* log_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("log");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_logClassic);
    tcase_add_test(tc_core, s21_logBig);
    tcase_add_test(tc_core, s21_logLow);
    tcase_add_test(tc_core, s21_logNan);
    tcase_add_test(tc_core, s21_logInf);
    tcase_add_test(tc_core, s21_logZero);
    tcase_add_test(tc_core, s21_logBelowzero);

    suite_add_tcase(s, tc_core);

    return s;
}

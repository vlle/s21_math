#include "../s21_math.h"
#include <check.h>

START_TEST(s21_sqrtZero) {
    double y = 0;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtBig) {
    double y = 1131112.1232131231421;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtClassic) {
    double y = 1.1232131231421;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtLessZero) {
    double y = -123112.412;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_sqrtNan) {
    double y = S21_NAN;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_sqrtInf) {
    double y = S21_INF;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_infinite(my_ans);
    ck_assert_ldouble_infinite(true_ans);
} END_TEST

Suite* sqrt_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sqrt");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_sqrtZero);
    tcase_add_test(tc_core, s21_sqrtBig);
    tcase_add_test(tc_core, s21_sqrtClassic);
    tcase_add_test(tc_core, s21_sqrtLessZero);
    tcase_add_test(tc_core, s21_sqrtInf);
    tcase_add_test(tc_core, s21_sqrtNan);
    suite_add_tcase(s, tc_core);

    return s;
}

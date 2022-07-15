#include "../s21_math.h"
#include <check.h>

START_TEST(s21_asinClassic) {
    double x = 0.412312355;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_asinZero) {
    double x = 0.0;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_asinBelowZero) {
    double x = -0.412312355;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_asinPi) {
    double x = S21_PI;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_asinPi2) {
    double x = S21_PI / 2;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_asinMoreOne) {
    double x = 1.412312355;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_asinInf) {
    double x = S21_INF;
    long double a2 = asin(x);
    long double b2 = s21_asin(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_asinNan) {
    int y = S21_NAN;
    long double my_ans = s21_asin(y);
    long double true_ans = asin(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

Suite* asin_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("asin");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_asinClassic);
    tcase_add_test(tc_core, s21_asinZero);
    tcase_add_test(tc_core, s21_asinBelowZero);
    tcase_add_test(tc_core, s21_asinPi);
    tcase_add_test(tc_core, s21_asinPi2);
    tcase_add_test(tc_core, s21_asinInf);
    tcase_add_test(tc_core, s21_asinNan);
    tcase_add_test(tc_core, s21_asinMoreOne);

    suite_add_tcase(s, tc_core);

    return s;
}


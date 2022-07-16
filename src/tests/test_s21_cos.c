#include "../s21_math.h"
#include <check.h>

START_TEST(s21_cosClassic) {
    double x = 0.412312355;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosLow) {
    double x = -12310.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosBig) {
    double x = 1312.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosZero) {
    double x = 0.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosBelowZero) {
    double x = -0.412312355;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosNan) {
    double x = S21_NAN;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_cosInf) {
    double x = S21_INF;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

Suite* cos_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("cos");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_cosClassic);
    tcase_add_test(tc_core, s21_cosZero);
    tcase_add_test(tc_core, s21_cosBelowZero);
    tcase_add_test(tc_core, s21_cosBig);
    tcase_add_test(tc_core, s21_cosLow);
    tcase_add_test(tc_core, s21_cosNan);
    tcase_add_test(tc_core, s21_cosInf);

    suite_add_tcase(s, tc_core);

    return s;
}

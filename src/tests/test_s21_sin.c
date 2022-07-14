#include "../s21_math.h"
#include <check.h>

START_TEST(s21_sinClassic) {
    double x = 0.412312355;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinZero) {
    double x = 0.0;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinBelowZeroMuch) {
    double x = -842.0;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinBelowZero) {
    double x = -0.412312355;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

Suite* sin_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sin");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_sinClassic);
    tcase_add_test(tc_core, s21_sinZero);
    tcase_add_test(tc_core, s21_sinBelowZero);
    tcase_add_test(tc_core, s21_sinBelowZeroMuch);

    suite_add_tcase(s, tc_core);

    return s;
}

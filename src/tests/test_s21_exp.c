#include "../s21_math.h"
#include <check.h>

START_TEST(s21_expClassic) {
    double x = 3;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_expBig) {
    double x = 3132;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_expLow) {
    double x = -123;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_expZero) {
    double x = 0;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_expBelowzero) {
    double x = -2;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

Suite* exp_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("exp");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_expClassic);
    tcase_add_test(tc_core, s21_expBig);
    tcase_add_test(tc_core, s21_expLow);
    tcase_add_test(tc_core, s21_expZero);
    tcase_add_test(tc_core, s21_expBelowzero);

    suite_add_tcase(s, tc_core);

    return s;
}
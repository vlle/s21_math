#include "../s21_math.h"
#include <check.h>

START_TEST(s21_expClassic) {
    double x = 3;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_expBig) {
    double x = 20;
    long double a2 = expl(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_eq_tol(a2, b2, 0.001);
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

START_TEST(s21_expNan) {
    double x = S21_NAN;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_expInf) {
    double x = S21_INF;
    long double a2 = exp(x);
    long double b2 = s21_exp(x);
    ck_assert(a2 == b2);
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
    tcase_add_test(tc_core, s21_expNan);
    tcase_add_test(tc_core, s21_expInf);

    suite_add_tcase(s, tc_core);

    return s;
}

#include "../s21_math.h"
#include <check.h>

START_TEST(s21_powClassic) {
    double x = 0.412312355;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powUnusual) {
    double x = 4412441.0;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powLessZero) {
    double x = -10.0;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-07);
} END_TEST

START_TEST(s21_powDouble1) {
    double x = 1010.312;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powDouble2) {
    double x = 120;
    double base = 3.4;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powZeroBase) {
    double x = 5;
    double base = 0;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powZero) {
    double x = 0;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powLesszero) {
    double x = -132445;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

Suite* pow_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("pow");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_powClassic);
    tcase_add_test(tc_core, s21_powUnusual);
    tcase_add_test(tc_core, s21_powZero);
    tcase_add_test(tc_core, s21_powZeroBase);
    tcase_add_test(tc_core, s21_powLessZero);
    tcase_add_test(tc_core, s21_powDouble1);
    tcase_add_test(tc_core, s21_powDouble2);
    suite_add_tcase(s, tc_core);

    return s;
}

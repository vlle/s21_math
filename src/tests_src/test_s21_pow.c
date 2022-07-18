#include "../s21_math.h"
#include <check.h>

START_TEST(s21_powClassic) {
    double x = 0.412312355;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powZeroInf) {
    double x = 0;
    double base = -1.0;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_infinite(a2);
    ck_assert_ldouble_infinite(b2);
} END_TEST

START_TEST(s21_powMinusInf) {
    double x = -1;
    double base = -S21_INF;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powZeroNan) {
    double x = 0;
    double base = S21_NAN;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_powInfMinus) {
    double x = S21_INF;
    double base = -1;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powUnusual) {
    double x = 441.0;
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
    double x = 100.312;
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
    double x = -134;
    double base = 3;
    long double a2 = pow(x, base);
    long double b2 = s21_pow(x, base);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_powNan) {
    double y = S21_NAN;
    long double my_ans = s21_pow(y, 0);
    long double true_ans = pow(y, 0);
    ck_assert(my_ans == true_ans);
} END_TEST

START_TEST(s21_powInf) {
    double y = S21_INF;
    long double my_ans = s21_pow(y, 1);
    long double true_ans = pow(y, 1);
    ck_assert(my_ans == true_ans);
} END_TEST

Suite* pow_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("pow");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_powClassic);
    tcase_add_test(tc_core, s21_powUnusual);
    tcase_add_test(tc_core, s21_powZero);
    tcase_add_test(tc_core, s21_powInf);
    tcase_add_test(tc_core, s21_powNan);
    tcase_add_test(tc_core, s21_powLesszero);
    tcase_add_test(tc_core, s21_powZeroBase);
    tcase_add_test(tc_core, s21_powLessZero);
    tcase_add_test(tc_core, s21_powDouble1);
    tcase_add_test(tc_core, s21_powZeroInf);
    tcase_add_test(tc_core, s21_powInfMinus);
    tcase_add_test(tc_core, s21_powMinusInf);
    tcase_add_test(tc_core, s21_powZeroNan);
    tcase_add_test(tc_core, s21_powDouble2);
    suite_add_tcase(s, tc_core);

    return s;
}

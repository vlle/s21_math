#include "../s21_math.h"
#include <check.h>
START_TEST(s21_floorInf) {
    double x = S21_INF;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    // ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
    ck_assert_ldouble_infinite(a2);
    ck_assert_ldouble_infinite(b2);
} END_TEST

START_TEST(s21_floorNan) {
    double x = S21_NAN;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_floorClassic) {
    double x = 0.412312355;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_floorClassicNegative) {
    double x = -1.788987;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST


START_TEST(s21_floorUnusual) {
    double x = 5.123231;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_floorBig) {
    double x = 5.55555123123123213123123123;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_floorInt) {
    double x = -6.000000;
    long double a2 = floor(x);
    long double b2 = s21_floor(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

Suite* floor_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("floor");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_floorInf);
    tcase_add_test(tc_core, s21_floorNan);
    tcase_add_test(tc_core, s21_floorClassic);
    tcase_add_test(tc_core, s21_floorUnusual);
    tcase_add_test(tc_core, s21_floorClassicNegative);
    tcase_add_test(tc_core, s21_floorInt);
    tcase_add_test(tc_core, s21_floorBig);
    suite_add_tcase(s, tc_core);

    return s;
}

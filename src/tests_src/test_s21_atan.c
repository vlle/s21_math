#include "../s21_math.h"
#include <check.h>

START_TEST(s21_atanZero) {
    double x = 0.0;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_atanLesszero) {
    double x = -0.56;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_atanBig) {
    double x = 1312.412312355;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_atanLow) {
    double x = -123.412312355;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_atanClassic) {
    double x = 0.412312355;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_atanNan) {
    double x = S21_NAN;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_atanInf) {
    double x = S21_INF;
    long double a2 = atan(x);
    long double b2 = s21_atan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

Suite* atan_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("atan");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_atanClassic);
    tcase_add_test(tc_core, s21_atanLesszero);
    tcase_add_test(tc_core, s21_atanZero);
    tcase_add_test(tc_core, s21_atanInf);
    tcase_add_test(tc_core, s21_atanNan);
    tcase_add_test(tc_core, s21_atanBig);
    tcase_add_test(tc_core, s21_atanLow);
    suite_add_tcase(s, tc_core);

    return s;
}

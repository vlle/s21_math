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

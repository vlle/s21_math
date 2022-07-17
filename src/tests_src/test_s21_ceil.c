#include <check.h>
#include "../s21_math.h"

START_TEST(s21_ceilClassic) {
    double x = 83.9283;
    long double my_ans = s21_ceil(x);
    long double true_ans = ceil(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_ceilBig) {
    double x = 1231783.9283;
    long double my_ans = s21_ceil(x);
    long double true_ans = ceil(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_ceilZero) {
    double x = 0;
    long double my_ans = s21_ceil(x);
    long double true_ans = ceil(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_ceil_negative) {
    double x = -783.9283;
    long double my_ans = s21_ceil(x);
    long double true_ans = ceil(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_ceil_positive) {
    double x = 3671.43561;
    long double my_ans = s21_ceil(x);
    long double true_ans = ceil(x);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_ceilNan) {
    double y = S21_NAN;
    long double my_ans = s21_ceil(y);
    long double true_ans = ceil(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_ceilInf) {
    double y = S21_INF;
    long double my_ans = s21_ceil(y);
    long double true_ans = ceil(y);
    ck_assert_ldouble_infinite(my_ans);
    ck_assert_ldouble_infinite(true_ans);
} END_TEST

Suite* ceil_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("ceil");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_ceilClassic);
    tcase_add_test(tc_core, s21_ceilBig);
    tcase_add_test(tc_core, s21_ceilZero);
    tcase_add_test(tc_core, s21_ceil_negative);
    tcase_add_test(tc_core, s21_ceil_positive);
    tcase_add_test(tc_core, s21_ceilInf);
    tcase_add_test(tc_core, s21_ceilNan);
    suite_add_tcase(s, tc_core);

    return s;
}

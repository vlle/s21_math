#include "../s21_math.h"
#include <check.h>

START_TEST(s21_fmod_zero_division) {
    double x = 42647.78;
    double y = 0.0;
    long double my_ans = s21_fmod(x, y);
    long double true_ans = fmod(x, y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_fmod_both_positive) {
    double x = 4.56782;
    double y = 1.6783;
    long double my_ans = s21_fmod(x, y);
    long double true_ans = fmod(x, y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fmod_both_negative) {
    double x = -1324.78932;
    double y = -9.56781;
    long double my_ans = s21_fmod(x, y);
    long double true_ans = fmod(x, y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fmod_one_positive) {
    double x = 678162.9;
    double y = -6788219.7812;
    long double my_ans = s21_fmod(x, y);
    long double true_ans = fmod(x, y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fmod_one_negative) {
    double x = -452163.21;
    double y = 118231.29;
    long double my_ans = s21_fmod(x, y);
    long double true_ans = fmod(x, y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fmodNan) {
    double y = S21_NAN;
    long double my_ans = s21_fmod(y, 2);
    long double true_ans = fmod(y, 2);
    ck_assert_ldouble_nan(true_ans);
    ck_assert_ldouble_nan(my_ans);
} END_TEST

START_TEST(s21_fmodInf) {
    double y = S21_INF;
    long double my_ans = s21_fmod(y, 2);
    long double true_ans = fmod(y, 2);
    ck_assert_ldouble_nan(true_ans);
    ck_assert_ldouble_nan(my_ans);
} END_TEST

START_TEST(s21_fmodWhat) {
  ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
}
END_TEST

START_TEST(s21_fmodWhat2) {
  double num = NAN;
  long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

Suite* fmod_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("fmod");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_fmodWhat);
    tcase_add_test(tc_core, s21_fmodWhat2);
    tcase_add_test(tc_core, s21_fmod_both_positive);
    tcase_add_test(tc_core, s21_fmod_both_negative);
    tcase_add_test(tc_core, s21_fmod_one_positive);
    tcase_add_test(tc_core, s21_fmod_one_negative);
    tcase_add_test(tc_core, s21_fmod_zero_division);
    tcase_add_test(tc_core, s21_fmodNan);
    tcase_add_test(tc_core, s21_fmodInf);

    suite_add_tcase(s, tc_core);

    return s;
}


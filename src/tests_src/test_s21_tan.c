#include "../s21_math.h"
#include <check.h>

START_TEST(s21_tanClassic) {
    double x = 0.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanMorezero) {
    double x = 2.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanZero) {
    double x = 0.0;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanLesszero) {
    double x = -0.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanLessVeryzero) {
    double x = -13.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanVeryVerylesszero) {
    double x = -131231.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanNan) {
    double y = S21_NAN;
    long double my_ans = s21_tan(y);
    long double true_ans = tan(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

START_TEST(s21_tanInf) {
    double y = S21_INF;
    long double my_ans = s21_tan(y);
    long double true_ans = tan(y);
    ck_assert_ldouble_nan(my_ans);
    ck_assert_ldouble_nan(true_ans);
} END_TEST

Suite* tan_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("tan");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_tanClassic);
    tcase_add_test(tc_core, s21_tanLesszero);
    tcase_add_test(tc_core, s21_tanZero);
    tcase_add_test(tc_core, s21_tanLessVeryzero);
    tcase_add_test(tc_core, s21_tanVeryVerylesszero);
    tcase_add_test(tc_core, s21_tanMorezero);
    tcase_add_test(tc_core, s21_tanInf);
    tcase_add_test(tc_core, s21_tanNan);
    suite_add_tcase(s, tc_core);

    return s;
}

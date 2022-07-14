#include <check.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tests/s21_math_test.h"
#include "s21_math.h"

START_TEST(s21_absClassic) {
    int y = -1;
    long int my_ans = s21_abs(y);
    long int true_ans = abs(y);
    ck_assert_int_eq(my_ans, true_ans);
} END_TEST




START_TEST(s21_cosClassic) {
    double x = 0.412312355;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosLow) {
    double x = -12310.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosBig) {
    double x = 1312.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosZero) {
    double x = 0.0;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_cosBelowZero) {
    double x = -0.412312355;
    long double a2 = cos(x);
    long double b2 = s21_cos(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST


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

START_TEST(s21_logClassic) {
    double x = 3;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_logBig) {
    double x = 3132;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_logLow) {
    double x = -123;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
} END_TEST

START_TEST(s21_logZero) {
    double x = 0;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    // ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
    ck_assert_ldouble_infinite(a2);
    ck_assert_ldouble_infinite(b2);
} END_TEST

START_TEST(s21_logBelowzero) {
    double x = -2;
    long double a2 = log(x);
    long double b2 = s21_log(x);
    // ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
    ck_assert_ldouble_nan(a2);
    ck_assert_ldouble_nan(b2);
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
    tcase_add_test(tc_core, s21_floorBig);
    suite_add_tcase(s, tc_core);

    return s;
}


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


Suite* abs_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("abs");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_absClassic);
    suite_add_tcase(s, tc_core);

    return s;
}





Suite* cos_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("cos");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_cosClassic);
    tcase_add_test(tc_core, s21_cosZero);
    tcase_add_test(tc_core, s21_cosBelowZero);
    tcase_add_test(tc_core, s21_cosBig);
    tcase_add_test(tc_core, s21_cosLow);

    suite_add_tcase(s, tc_core);

    return s;
}

Suite* asin_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("asin");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_asinClassic);
    tcase_add_test(tc_core, s21_asinZero);
    tcase_add_test(tc_core, s21_asinBelowZero);
    tcase_add_test(tc_core, s21_asinPi);
    tcase_add_test(tc_core, s21_asinPi2);
    tcase_add_test(tc_core, s21_asinMoreOne);

    suite_add_tcase(s, tc_core);

    return s;
}

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

Suite* log_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("log");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_logClassic);
    tcase_add_test(tc_core, s21_logBig);
    tcase_add_test(tc_core, s21_logLow);
    tcase_add_test(tc_core, s21_logZero);
    tcase_add_test(tc_core, s21_logBelowzero);

    suite_add_tcase(s, tc_core);

    return s;
}

int main() {
    int no_failed = 0;
    Suite *a, *b, *c, *d, *e, *f, *g, *h, *m, *l,  *n,  *j, *z, *t;
    SRunner* runner;
    a = floor_suite();
    b = tan_suite();
    c = abs_suite();
    d = acos_suite();
    e = fmod_suite();
    f = ceil_suite();
    g = atan_suite();
    h = fabs_suite();
    m = pow_suite();
    l = asin_suite();
    // h = asin_suite();
    // n = asin_suite();
    j = sin_suite();
    z = cos_suite();
    t = exp_suite();
    n = log_suite();

    runner = srunner_create(a);
    srunner_add_suite(runner, b);
    srunner_add_suite(runner, c);
    srunner_add_suite(runner, d);
    srunner_add_suite(runner, e);
    srunner_add_suite(runner, f);
    srunner_add_suite(runner, g);
    srunner_add_suite(runner, h);
    srunner_add_suite(runner, m);
    srunner_add_suite(runner, l);
    srunner_add_suite(runner, n);
    srunner_add_suite(runner, j);
    srunner_add_suite(runner, z);
    srunner_add_suite(runner, t);
    srunner_run_all(runner, CK_NORMAL);
    no_failed = srunner_ntests_failed(runner);
    srunner_free(runner);
    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

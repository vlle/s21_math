#include <check.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "tests/s21_math_test.h"
#include "s21_math.h"

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

// START_TEST(s21_acos_too_negative) {
//     double x = -12.781;
//     long double my_ans = s21_acos(x);
//     long double true_ans = acos(x);
//     ck_assert_ldouble_nan(my_ans);
//     ck_assert_ldouble_nan(true_ans);
// } END_TEST
//
// START_TEST(s21_acos_negative) {
//     double x = -0.67218;
//     long double my_ans = s21_acos(x);
//     long double true_ans = acos(x);
//     ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
// } END_TEST
//
// START_TEST(s21_acos_zero) {
//     double x = 1.0;
//     long double my_ans = s21_acos(x);
//     long double true_ans = acos(x);
//     ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
// } END_TEST
// 
// START_TEST(s21_acos_positive) {
//     double x = 0.4125638719;
//     long double my_ans = s21_acos(x);
//     long double true_ans = acos(x);
//     ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
// } END_TEST
// 
// START_TEST(s21_acos_too_positive) {
//     double x = 5.64278;
//     long double my_ans = s21_acos(x);
//     long double true_ans = acos(x);
//     ck_assert_ldouble_nan(my_ans);
//     ck_assert_ldouble_nan(true_ans);
// } END_TEST

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

START_TEST(s21_fabsZero) {
    double y = 0.0;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fabsBig) {
    double y = 123123.1232131231421;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_fabsClassic) {
    double y = -1.1232131231421;
    long double my_ans = s21_fabs(y);
    long double true_ans = fabs(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_absClassic) {
    int y = -1;
    long int my_ans = s21_abs(y);
    long int true_ans = abs(y);
    ck_assert_int_eq(my_ans, true_ans);
} END_TEST

START_TEST(s21_sqrtZero) {
    double y = 0;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtBig) {
    double y = 1131112.1232131231421;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtClassic) {
    double y = 1.1232131231421;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_sqrtLessZero) {
    double y = -123112.412;
    long double my_ans = s21_sqrt(y);
    long double true_ans = sqrt(y);
    ck_assert_ldouble_eq_tol(my_ans, true_ans, 1e-7);
} END_TEST

START_TEST(s21_tanClassic) {
    double x = 0.56;
    long double a2 = tan(x);
    long double b2 = s21_tan(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_tanMorezero) {
    double x = 12.56;
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

START_TEST(s21_sinClassic) {
    double x = 0.412312355;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinZero) {
    double x = 0.0;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinBelowZeroMuch) {
    double x = -842.0;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
    ck_assert_ldouble_eq_tol(a2, b2, 1e-7);
} END_TEST

START_TEST(s21_sinBelowZero) {
    double x = -0.412312355;
    long double a2 = sin(x);
    long double b2 = s21_sin(x);
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

Suite* atan_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("atan");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_atanClassic);
    tcase_add_test(tc_core, s21_atanLesszero);
    tcase_add_test(tc_core, s21_atanZero);
    tcase_add_test(tc_core, s21_atanBig);
    tcase_add_test(tc_core, s21_atanLow);
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

Suite* fabs_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("fabs");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_fabsClassic);
    tcase_add_test(tc_core, s21_fabsZero);
    tcase_add_test(tc_core, s21_fabsBig);
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* sqrt_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sqrt");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_sqrtZero);
    tcase_add_test(tc_core, s21_sqrtBig);
    tcase_add_test(tc_core, s21_sqrtClassic);
    tcase_add_test(tc_core, s21_sqrtLessZero);
    suite_add_tcase(s, tc_core);

    return s;
}

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
    suite_add_tcase(s, tc_core);

    return s;
}

Suite* fmod_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("fmod");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, s21_fmod_both_positive);
    tcase_add_test(tc_core, s21_fmod_both_negative);
    tcase_add_test(tc_core, s21_fmod_one_positive);
    tcase_add_test(tc_core, s21_fmod_one_negative);
    tcase_add_test(tc_core, s21_fmod_zero_division);

    suite_add_tcase(s, tc_core);

    return s;
}

// Suite* acos_suite(void) {
//     Suite* s;
//     TCase* tc_core;
// 
//     s = suite_create("acos");
//     tc_core = tcase_create("Core");
// 
//     tcase_add_test(tc_core, s21_acos_too_negative);
//     tcase_add_test(tc_core, s21_acos_negative);
//     tcase_add_test(tc_core, s21_acos_zero);
//     tcase_add_test(tc_core, s21_acos_positive);
//     tcase_add_test(tc_core, s21_acos_too_positive);
// 
//     suite_add_tcase(s, tc_core);
// 
//     return s;
// }
// 
Suite* sin_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("sin");
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, s21_sinClassic);
    tcase_add_test(tc_core, s21_sinZero);
    tcase_add_test(tc_core, s21_sinBelowZero);
    tcase_add_test(tc_core, s21_sinBelowZeroMuch);

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

#include "s21_math.h"

long double s21_acos(double x) {
    long double y = (S21_PI / 2);
    if (x == 1.0) {
        y = 0;
    } else if (x == -1.) {
        y = S21_PI;
    } else if (s21_fabs(x) <= 1.0) {
        y -= s21_asin(x);
    } else {
        y = S21_NAN;
    }
    // long double y = S21_NAN;
    // if (x < 1 && x >= 0) {
    //     y = s21_atan(s21_sqrt(1 - s21_pow(x, 2.0)) / x);
    //     // workerco: s21_atan perfomance poorly when x == 0.0. i dont understand why yet.
    //     // it outputs nan instead of 1.5708
    //     // workerco: this variant of acos works good. maybe we can use some stuff from here?
    //     // https://github.com/NasonovIvan/s21_math/blob/main/src/s21_acos.c
    // } else if (x < 0 && x > -1) {
    //     y = S21_PI + s21_atan(s21_sqrt(1 - s21_pow(x, 2.0)) / x);
    // }
    return y;
}

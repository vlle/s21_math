#include "s21_math.h"

long double s21_atan(double x) {
    long double s21_atan = 0;
    if (is_nan(x)) return S21_NAN;
    if (x == S21_INF || x == -S21_INF) {
        s21_atan = x < 0 ? -S21_PI / 2 : S21_PI / 2;
    } else if (-1. < x && x < 1.) {
        for (register int i = 0; i < 500; i++) {
            s21_atan += ((s21_pow(-1, i) * s21_pow(x, 1 + (2 * i))) / (1 + (2 * i)));
        }
    } else {
        for (register int i = 0; i < 900; i++) {
            s21_atan += ((s21_pow(-1, i) * s21_pow(x, -1 - (2 * i))) / (1 + (2 * i)));
        }
        s21_atan = S21_PI * s21_sqrt(x * x) / (2 * x) - s21_atan;
    }
    return s21_atan;
}

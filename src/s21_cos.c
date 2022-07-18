#include "s21_math.h"

long double s21_cos(double x) {
    long double s21_cos = 0;
    if ((is_nan(x)) || (is_inf(x))) return S21_NAN;
    while ((x > 2 * S21_PI) || (x < -2 * S21_PI)) {
        if (x > 2 * S21_PI) {
            x = x - 2 * S21_PI;
        }
        if (x < -2 * S21_PI) {
            x = x + 2 * S21_PI;
        }
    }
    for (register int i = 0; i < 50; i++) {
        s21_cos += s21_pow(-1, i) * ((s21_pow(x, 2 * i)) / (s21_fact(2 * i)));
    }
    return s21_cos;
}


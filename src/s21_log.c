#include "s21_math.h"

long double s21_log(double x) {
    int ex_pow = 0;
    long double result = 0, compare = result;
    if ((x < 0) || (is_nan(x))) {
        return S21_NAN;
    } else if (x == 0) {
        return -S21_INF;
    } else if ((is_inf(x))) {
        return S21_INF;
    }
    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;

    for (int i = 0; i < 100; i++) {
        compare = result;
        result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    return (long double) result + ex_pow;
}


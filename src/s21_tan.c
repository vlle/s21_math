#include "s21_math.h"

long double s21_tan(double x) {
    // if (x == S21_INF) return S21_NAN;
    return s21_sin(x) / s21_cos(x);
}

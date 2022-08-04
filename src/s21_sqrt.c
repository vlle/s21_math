#include "s21_math.h"

long double s21_sqrt(double x) {
    if ((is_nan(x)) || (x < 0)) {
        return S21_NAN;
    } else if ((is_inf(x))) {
        return S21_INF;
    }
    return s21_pow(x, 0.5);
}

#include "s21_math.h"

long double s21_ceil(double x) {
    long double y = (int) x;
    if ((is_nan(x))) {
        return (S21_NAN);
    } else if ((is_inf(x))) {
        return S21_INF;
    }
    if (x > y) {
        y += 1.0;
    }
    return y;
}

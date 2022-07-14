#include "s21_math.h"
//  returns the nearest integer not greater than the given value

long double s21_floor(double x) {
    if (is_inf(x)) {
        return S21_INF;
    }
    if (is_nan(x)) {
        return S21_NAN;
    }
    return (int) x;
}

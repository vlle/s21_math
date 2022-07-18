#include "s21_math.h"
//  returns the nearest integer not greater than the given value

long double s21_floor(double x) {
    if (is_inf(x)) {
        return S21_INF;
    }
    if (is_nan(x)) {
        return S21_NAN;
    }
    if (x >= 0) {
        return (long int) x;
    } else {
        if ((x - (long) x) <= -0.0000001) {
            return (long int) x - 1;
        } else {
            return x;
        }
    }
}

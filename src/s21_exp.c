#include "s21_math.h"
#include <float.h>

long double s21_exp(double x) {
    long double y, q, ex;
    int i, p;
    if (is_inf(x)) {
        return S21_INF;
    } else if (is_nan(x)) {
        return S21_NAN;
    }
    p = s21_floor(x);  //  Выделение целой части х - p
    q = x - p;          //  Выделение дробной части х - q
    ex = S21_EXP;
    y = 1;
    i = 1;
    if (x) {
        if (p) {
            do {
                y *= ex;
                i++;
            } while (i <= s21_fabs(p));
            if (p < 0)
                y = 1 / y;
        }
        if (q) {
            long double s = 1;
            long double a = 1;
            i = 1;
            do {
                a *= q / i;
                s += a;
                i++;
            } while (s21_fabs(a) >= 1e-20/ y);
            y *= s;
        }
    }
    return y;
}

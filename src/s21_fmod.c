#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double ans = (long double) x;
    if ((is_nan(x)) || (is_inf(x))) return S21_NAN;
    if ((is_nan(y)) || (is_inf(y))) return S21_NAN;
    if (y > 0) {
        if (ans >= 0) {
            while (ans >= y)
                ans -= y;
        } else {
            while (ans <= -y)
                ans += y;
        }
    } else if (y != 0) {
        while (ans <= y)
            ans -= y;
    } else {
        ans = S21_NAN;
    }
    return ans;
}

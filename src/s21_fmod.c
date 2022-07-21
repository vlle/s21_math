#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double ans = (long double) x;
    if ((is_nan(x)) || (is_inf(x) || is_nan(y)) || (is_inf(y) || y == 0)) {
        ans = S21_NAN;
    } else if (y > 0) {
        if (ans >= 0)
            while (ans >= y)
                ans -= y;
        else
            while (ans <= -y)
                ans += y;
    } else {
        if (ans <= 0)
            while (ans <= y)
                ans -= y;
        else
            while (ans >= -y)
                ans += y;
    }
    return ans;
}

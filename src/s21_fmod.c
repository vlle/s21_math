#include "s21_math.h"

long double s21_fmod(double x, double y) {
    long double ans = (long double) x;
    if (y > 0) {
        while (ans >= y) {
            ans -= y;
        }
    } else if (y != 0) {
        while (ans <= y) {
            ans -= y;
        }
    } else {
        ans = S21_NAN;
    }
    return ans;
}

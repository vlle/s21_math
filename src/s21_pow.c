#include "s21_math.h"


long double s21_pow(double base, double exps) {
    long double n = base;
    long double res = 0;
    if ((base == 0) && (is_nan(exps))) {
        return S21_NAN;
    } else if ((base == 0) && (exps < 0)) {
        return S21_INF;
    } else if ((base == S21_INF) && (exps < 0)) {
        return 0;
    } else if ((base == -1) && (exps == -S21_INF)) {
        return 1;
    }
    if (exps == 0) {
        res = 1;
    } else {
        if (base == 0) {
            res = 0;
        } else {
            if (n < 0) {
                res = s21_exp(exps*s21_log(-n));
                if (s21_fmod(exps, 2) != 0) {
                    res = res * -1;
                }
            } else {
                res = s21_exp(exps*s21_log(n));
            }
        }
    }
    return res;
}

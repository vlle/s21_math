#include "s21_math.h"
#include <math.h>

long double s21_pow(double base, double exps) {
    long double n = base;
    long double res = 0;
    if (exps == 0) {
        res = 1;
    } else {
        if (n < 0) {
            res = exp(exps*log(-n));
            if (s21_fmod(exps, 2) != 0) {
                res = res * -1;
            }
        } else {
            res = exp(exps*log(n));
        }
    }
    return res;
}


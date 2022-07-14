#include "s21_math.h"

long double s21_log(double x) {
    // double alpha = (x-1)/(x+1), ans = alpha;
    // double save = ans * alpha * alpha;

    // for (register int i = 2 ; i <= 10000 ; i++) {
    //     ans += (1.0/(2*i-1)) * save;
    //     save = save * alpha * alpha;
    // }

//     return (2.0 * ans);
    int ex_pow = 0;
    double result = 0, compare = result;

    for (; x >= S21_EXP; x /= S21_EXP, ex_pow++) continue;

    for (int i = 0; i < 100; i++) {
        compare = result;
        result = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
    return (long double) result + ex_pow;
}


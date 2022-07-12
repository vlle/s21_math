#include "s21_math.h"

long double s21_fact(double base) {
    long double n = 1;
    long double res = 1;
    while (n <= base) {
        res = res*n;
        n++;
    }
    return res;
}


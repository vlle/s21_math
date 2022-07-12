#include "s21_math.h"

long double s21_cos(double x) {
    long double s21_cos = 0;
    for (register int i = 0; i < 45; i++) {
        s21_cos += s21_pow(-1, i) * ((s21_pow(x, 2 * i)) / (s21_fact(2 * i)));
    }
    return s21_cos;
}

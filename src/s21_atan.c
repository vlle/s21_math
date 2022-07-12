#include "s21_math.h"

long double s21_atan(double x) {
    long double s21_atan = 0;
    if (-1. < x && x < 1.) {
        for (register int i = 0; i < 5000; i++) {
           s21_atan += ((s21_pow(-1, i) * s21_pow(x, 1 + (2 * i))) / (1 + (2 * i)));
        }
    } else {
        for (register int i = 0; i < 9000; i++) {
           s21_atan += ((s21_pow(-1, i) * s21_pow(x, -1 - (2 * i))) / (1 + (2 * i)));
        }
        s21_atan = S21_PI * s21_sqrt(x * x) / (2 * x) - s21_atan;
    }
    return s21_atan;
}

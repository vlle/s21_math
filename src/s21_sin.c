#include "s21_math.h"

long double s21_sin(double x) {
    long double n = 0;
    long double sum = 0;
    while (x > 2 * S21_PI || x < -2 * S21_PI) {
        if (x > 2 * S21_PI) {
            x = x - 2 * S21_PI;
        }
        if (x < -2 * S21_PI) {
            x = x + 2 * S21_PI;
        }
    }
    while (n < 500) {
        sum += s21_pow(-1, n) * s21_pow(x, 2*n + 1) / s21_fact(2*n + 1);
        n++;
    }
    return sum;
}

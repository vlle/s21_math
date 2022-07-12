#include "s21_math.h"

long double s21_ceil(double x) {
    long double y = (int) x;
    if (x > y)
        y += 1.0;
    return y;
}

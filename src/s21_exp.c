#include "s21_math.h"

long double s21_exp(double x) {
    long double s21_exp = 1;
    for (register int i = 0; i < 500; i++) {
        s21_exp += (s21_pow(x, i)) / (s21_fact(i));
    }  // workerco: need to remake exp func. it depends on s21_pow and s21_pow depends on exp..
    return s21_exp;
}


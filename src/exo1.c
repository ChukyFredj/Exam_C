#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../header/exo1.h"

double mypow(double base, int exponent) {
    double result = 1.0;
    int i;
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }
    for (i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

double Suite(double x, unsigned int N) {
    double U0 = x;
    double Un = U0;
    int n;
    for (n = 1; n <= N; n++) {
        Un = Un + mypow(-1, n) * mypow(x, 2*n-1)/ (2*n-1);
    }
    return Un;
}

void exo1() {
    double x = 1.0;
    unsigned int N = 50;
    double res_suite = Suite(x, N);
    double res_atan = atan(x);
    printf("Suite : %f\natan : %f\n", res_suite, res_atan);
    return;
} 


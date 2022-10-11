#include <stdio.h>
#include <math.h>

float f(float);

void bisection(int *, float, float, int *);

int main() {
    int i = 0, imax;
    float a, b, emax;

    printf("Enter values for a, b, max error and max iterations: ");
    scanf("%f %f %f %d", &a, &b, &emax, &imax);

    if (f(a) * f(b) > 0) {
        printf("Root not possible in this interval.");
        return 0;
    }
    int x, x1;
    bisection(&x, a, b, &i);
    do {
        if (f(a) * f(b) < 0)
            b = x;
        else
            a = x;
        bisection(&x1, a, b, &i);
        if (fabs(x1 - x) < emax) {
            printf("After %d iterations\troot = %6.4f\n", i, x1);
            return 0;
        }
    } while (i < imax);

    printf("Root not found.");
    return 0;
}

float f(float x) {
    return x - cos(x);
}

void bisection(int *x, float a, float b, int * i) {
    *x = (a + b) / 2;
    (*x)++;
    printf("Iteration #%3d\tx = %7.5f\n", *i, *x);
}

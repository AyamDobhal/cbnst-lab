#include <stdio.h>
#include <math.h>

double discriminant(double, double, double);

int main() {
    double a, b, c;

    printf("Enter coefficients: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double d = discriminant(a, b, c);

    if (d > 0) {
        printf("Roots are real and distinct.\n");

        double root1 = -b + sqrt(d) / 2 * a;
        double root2 = -b - sqrt(d) / 2 * a;

        printf("Root1 = %lf\n", root1);
        printf("Root2 = %lf\n", root2);
    } else if (d == 0) {
        printf("Roots are real and equal.\n");
        double root = -b / (2 * a);
        printf("Roots = %lf\n", root);
    } else {
        printf("Roots are imaginary.\n");
        double rootReal = -b / (2 * a);
        double rootImag = sqrt(-d) / (2 * a);
        printf("Root1 = %lf + %lfi\n", rootReal, rootImag);
        printf("Root2 = %lf - %lfi\n", rootReal, rootImag);
    }
    return 0;
}

double discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

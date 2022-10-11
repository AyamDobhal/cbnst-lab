#include <stdio.h>
#include <math.h>

float f(float);

int main() {
    float x0, x1, emax;

    printf("Enter two initial guesses and max error: ");
    scanf("%f %f %f", &x0, &x1, &emax);

    float f0 = f(x0);
    float f1 = f(x1);

    if (f0 * f1 > 0) {
        printf("Invalid guess.\n");
        return 0;
    }
    float x2, f2;
    int step = 1;
    printf("Step\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);
        printf("%d\t\t%.4f\t\t%.4f\t\t%.4f\t\t%.4f\n", step, x0, x1, x2, f2);
        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }
        step++;
    } while (fabs(f2) > emax);
    printf("Root is %.4f", x2);
    return 0;
}

float f(float x) {
    return x * x - 5 * x + 3;
}

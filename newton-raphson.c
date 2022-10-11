#include <stdio.h>
#include <math.h>

// implement the function here
float f(float);

// implement the function's derivative here
float derivative(float);

int main() {
    float x, emax;
    int n;

    printf("Enter intial guess: ");
    scanf("%f", &x);

    printf("Enter max tolerable error: ");
    scanf("%f", &emax);

    printf("Enter no. of iterations: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        float d = derivative(x);
        if (d == 0) {
            printf("Division by zero not possible.\n");
            return 0;
        }
        float h = f(x) / d;
        x = x - h;
        printf("Iteration #%d\t\tx = %f\n", i, fabs(x));
        if (fabs(h) < emax) {
            printf("After %d iterations\troot = %f\n", i, fabs(x));
            return 0;
        }
    }
    printf("The required solution does not converge in this iteration range.");
    return 0;
}

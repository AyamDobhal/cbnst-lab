#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    printf("Enter no. of vars: ");
    scanf("%d", &n);

    // allocate memory for the matrix
    float **arr = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) 
        arr[i] = (float *)malloc((n + 1) * sizeof(float));
    
    for (int i = 0; i < n; i++) {
        printf("Enter coefficients and constant for eq %d: ", i + 1);
        for (int j = 0; j < n + 1; j++) {
            scanf("%f", &arr[i][j]);
        }
    }

    // converting into upper triangular matrix
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i > j) {
                float c = arr[i][j] / arr[j][j];
                for (int k = 0; k < n + 1; k++)
                    arr[i][k] -= c * arr[j][k];
            }
        }
    }

    // allocate memory for solution matrix
    float *x = (float *)malloc(n * sizeof(float));
    x[n - 1] = arr[n - 1][n] / arr[n - 1][n - 1];

    // backward substitution
    for (int i = n - 2; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += arr[i][j] * x[j];
        }
        x[i] = (arr[i][n] - sum) / arr[i][i];
    }

    // display the solution
    printf("Solution\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\t\t", i + 1, x[i]);
    }

    // release memory
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
    free(x);
    return 0;
}

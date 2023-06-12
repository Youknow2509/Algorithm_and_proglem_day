#include <stdio.h>
#include <math.h>

#define N 3
#define EPSILON 0.0001

void jacobiMethod(double A[N][N], double b[N], double x[N]) {
    double x_new[N];
    int i, j, k;
    double sum;

    for (k = 0; k < 100; k++) {
        for (i = 0; i < N; i++) {
            sum = 0.0;
            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum += A[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sum) / A[i][i];
        }

        int convergence = 1;
        for (i = 0; i < N; i++) {
            if (fabs(x_new[i] - x[i]) > EPSILON) {
                convergence = 0;
                break;
            }
        }

        if (convergence) {
            break;
        }

        for (i = 0; i < N; i++) {
            x[i] = x_new[i];
        }
    }
}

double infinityNorm(double T[N][N]) {
    double norm = 0.0;
    int i, j;

    for (i = 0; i < N; i++) {
        double rowSum = 0.0;
        for (j = 0; j < N; j++) {
            rowSum += fabs(T[i][j]);
        }
        if (rowSum > norm) {
            norm = rowSum;
        }
    }

    return norm;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double A[N][N];
    double b[N];
    double x[N];
    int i, j;

    printf("Nh?p ma tr?n A:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    printf("Nh?p vector b:\n");
    for (i = 0; i < N; i++) {
        scanf("%lf", &b[i]);
    }

    printf("Nh?p vector x(0):\n");
    for (i = 0; i < N; i++) {
        scanf("%lf", &x[i]);
    }

    jacobiMethod(A, b, x);

    printf("Nghi?m x:\n");
    for (i = 0; i < N; i++) {
        printf("%.4lf\n", x[i]);
    }

    double T[N][N];
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i != j) {
                T[i][j] = -A[i][j] / A[i][i];
            } else {
                T[i][j] = 0.0;
            }
        }
    }

    double norm = infinityNorm(T);
    printf("Chu?n vô cùng ma tr?n Tj: %.4lf\n", norm);

    return 0;
}
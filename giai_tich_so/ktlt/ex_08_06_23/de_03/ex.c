
#include <stdio.h>

int solve (int m, int n, float matrix[10001][10001]){
    int i, j;
    for ( i = 0; i < m; i++){
        for (j = 0; j < i; j++){
            if (matrix[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    /* char tentep[20]; scanf("%s", &tentep);

    FILE *inp = fopen(tentep, "r"); */

    FILE *inp = fopen("INP.TXT", "r");

    int m, n, i, j; // matrix: m hang, n cot ( ma tran vuong m = n)

    float matrix[m][n], s = 0, c = 0;

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            fscanf(inp, "%f", &matrix[i][j]);
        }
    }

    fclose(inp);

    for ( i = 0; i < m; i++){
        for (j = n - 1; j > n - 1 - i; j--){
            s += matrix[i][j];
            c++;
        }
    }

    printf("Trung binh cong cac diem nam duoi ma tran duong cheo phu la: %f\n", s/c);

    int checks = solve(m, n, matrix);

    if (checks){
        printf("Ma tran tren la ma tran duong cheo tren\n");
    }
    else{
        printf("Ma tran tren khong la ma tran duong cheo tren\n");
    }

    return 0;
}
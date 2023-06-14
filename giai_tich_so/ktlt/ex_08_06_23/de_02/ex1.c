#include <stdio.h>
#include <math.h>

float sum_matrix(int m, int n, float arr[10001][10001]){
    float res = 0;
    int i;
    for (i = 0; i < m; i++){
        int j;
        for (j = 0; j < n; j++){
            res += arr[i][j];
        }
    }
    return res;
}

void cau1(float tb_matrix, int m, int n, float arr[10001][10001]){
    float res = 0;
    int i;
    for (i = 0; i < m; i++){
        int j;
        for (j = 0; j < n; j++){
            if (arr[i][j] > tb_matrix){
                res += arr[i][j];
            }
        }
    }
    printf("Dap an cau 1: %f\n", res);
}

void cau2(int m, int n, float arr[10001][10001]){ // tuong duong tim phan tu be nhat 
    float res = arr[0][0];
    int i;
    for (i = 0; i < m; i++){
        int j;
        for (j = 0; j < n; j++){
            res = (res < arr[i][j]) ? res : arr[i][j];
        }
    }
    printf("Dap an cau 2: %f\n", res);  
}

void cau3(int m, int n, float arr[10001][10001]){
    printf("Dap an cau 3:\n");
    int i;
    for (i = 0; i < m; i++){
        int j;
        float temp = 0;
        for (j = 0; j < n; j++){
            temp += arr[i][j];            
        }
        printf("Tong cua hang %d la %f,\n", i, temp);
    }
}

int main(){
    int m, n, i;
    char name_file[20];
    // scanf("%s", name_file);
    FILE *inp = fopen("INP.TXT", "r");
    if (inp == NULL) {
        printf("Khong the mo file.\n");
        return 1;
    }
    fscanf(inp, "%d %d", &m, &n); // m hang, n cot.
    if (m <= 0 || n <= 0) {
        printf("Kich thuoc ma tran khong hop le.\n");
        return 1;
    }
    float arr[10001][10001];
    for (i = 0; i < m; i++){
        int j;
        for (j = 0; j < n; j++){
            fscanf(inp, "%f", &arr[i][j]);
        }
    }
    fclose(inp);

    float tb_matrix = sum_matrix(m, n, arr)/(m*n);
    cau1(tb_matrix, m, n, arr);
    cau2(m, n, arr);

    return 0;
}

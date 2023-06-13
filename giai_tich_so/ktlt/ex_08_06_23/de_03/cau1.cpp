
#include <stdio.h>

void in(int m, int n, int matrix[10001][10001]){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void cau2(int m, int n, int matrix[10001][10001]){
    int i, j;
    float s = 0, c = 0;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (matrix[i][j] % 2 == 0 && matrix[i][j] % 3 == 1){
                s += matrix[i][j];
                c++;
            }
        }
    }
    printf("Tong trung binh cac so chan va chia 3 du 1 la: %f", s/c);
}

void cau3(int m, int n, int matrix[10001][10001]){ // tinh tong tung hang
    int i, j, arr[n];
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            arr[i] += matrix[i][j];
        }
        printf("%d\t", arr[i]);
    }
}

void cau4 (int m, int n, int matrix[10001][10001], FILE *out){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            printf("%d\t", matrix[i]);
        }
        printf("%d\t", matrix[i]);
    }
}

int main(){

    char name_file[20]; scanf("%s", name_file);

    FILE *inp = fopen(name_file, "r"),
        *out = fopen("Show_screen/OUT.TXT", "w");
    
    int m, n, i, j;
    fscanf(inp, "%d %d", &m, &n); // m cot, n dong
    int matrix[n][m];

    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            fscanf(inp, "%f", &matrix[i][j]);
        }
    }

    fclose(inp);

    in(m, n, matrix);

    return 0;
}
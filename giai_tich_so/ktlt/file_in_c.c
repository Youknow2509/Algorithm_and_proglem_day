#include <stdio.h>

int main() {
    FILE *fp, *of;
    int rows, cols;
    int matrix[100][100];

    fp = fopen("Show_screen/INP.TXT", "r");
    of = fopen("Show_screen/OUT.TXT", "w");

    fscanf(fp, "%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%d", &matrix[i][j]);
        }
    }

//    printf("Ma tran:\n");
    fprintf(of, "Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
//            printf("%d\t", matrix[i][j]);
            fprintf(of,"%d\t", matrix[i][j]);
        }
//      printf("\n");
        fprintf(of, "\n");
    }

    int max_col = 0;
    int max_sum = 0;
    for (int j = 0; j < cols; j++) {
        int col_sum = 0;
        for (int i = 0; i < rows; i++) {
            col_sum += matrix[i][j];
        }
        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col = j;
        }
    }

//    printf("Cot co tong gia tri lon nhat la cot %d, voi tong gia tri la %d", max_col + 1, max_sum);
    fprintf(of, "Cot co tong gia tri lon nhat la cot %d, voi tong gia tri la %d", max_col + 1, max_sum);

    fclose(fp);
    fclose(of);

    return 0;
}

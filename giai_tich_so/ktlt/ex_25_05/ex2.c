
#include <stdio.h>
#include <stdlib.h>

// Cach 1:

int main(){

    FILE* inp = fopen("Show_screen/INP.TXT" , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int n, m; fscanf(inp, "%d %d", &m, &n);

    float **arr = (float**)malloc(m*sizeof(float*));
    for (int i = 0; i < n; i++){
        arr[i] = (float*)malloc(n*sizeof(float));
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(inp, "%f", &arr[i][j]);
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(out, "%f\t", arr[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(inp);
    fclose(out);
    
    for (int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// Cach 2:

/* 
int main(){

    FILE* inp = fopen("Show_screen/INP.TXT" , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int n, m; fscanf(inp, "%d %d", &m, &n);

    float *arr = (float**)malloc(m*n*sizeof(float));
    

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(inp, "%f", &arr[i*m + j]);
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(out, "%f\t", arr[i*m + j]);
        }
        fprintf(out, "\n");
    }

    fclose(inp);
    fclose(out);
    
    free(arr);

    return 0;
}
 */

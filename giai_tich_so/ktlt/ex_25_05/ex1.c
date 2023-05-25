
#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* inp = fopen("Show_screen/INP.TXT" , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");

    int n; fscanf(inp, "%d", &n);

    float *arr = (float*)malloc(n*sizeof(float));

    for (int i = 0; i < n; i++){
        fscanf(inp, "%f", &arr[i]);
    }

    int res = 0;
    for (int i = 2; i < n; i++){
        float d = arr[i - 1] - arr[i - 2];
        if ((arr[i] == arr[i - 1] + d) || (arr[i] == arr[i - 1] - 2*d) || (arr[i] == arr[i - 1] - d/2)){
            res ++;
        }
    }

    fprintf(out, "So day thoa man la: %d\n", res);

    fclose(inp);
    fclose(out);
    
    free(arr);

    return 0;
}
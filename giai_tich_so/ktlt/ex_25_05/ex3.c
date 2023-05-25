
#include <stdio.h>
#include <stdlib.h>

struct Sinhvien{
    char name[20];
    float point;
};

int main(){

    FILE* inp = fopen("Show_screen/INP.TXT" , "r"),
        * out = fopen("Show_screen/OUT.TXT" , "w");


    int n; fscanf(inp, "%d", &n);

    struct Sinhvien *arr = (struct Sinhvien *)malloc(n*sizeof(struct Sinhvien));

    for (int i = 0; i < n; i++){
        fscanf(inp, "%s %f", &arr[i].name, &arr[i].point);
    }

    for (int i = 0; i < n; i++){
        fprintf(out, "Ho va ten: %s %f diem\n", arr[i].name, arr[i].point);
    }

    fclose(inp);
    fclose(out);
    free(arr);

    return 0;
}
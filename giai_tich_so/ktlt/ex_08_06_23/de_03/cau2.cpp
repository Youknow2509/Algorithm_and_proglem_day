
#include <stdio.h>
#include <string.h>

struct people{
    char ten[20];
    int nam_sinh, nam_ket_nap;
};

const int nam = 2023;

void sort_nam_ket_nap (struct people *arr, int N){
    int i, j, temp;
    for (i = 0; i < N - 1; i++){
        for (j = i + 1; j < N; j++){
            if (arr[i].nam_ket_nap > arr[j].nam_ket_nap){
                temp = arr[i].nam_ket_nap;
                arr[i].nam_ket_nap = arr[j].nam_ket_nap;
                arr[j].nam_ket_nap = temp;
            }
        }
    }
}

void in_dang_vien_hon_20 (struct people *arr, int N){
    int i, j, temp;
    printf("Cac dang vien hon 20 nam tuoi dang la:\n");
    for (i = 0; i < N - 1; i++){
        if ( nam - arr[i].nam_ket_nap > 20){
            printf("\t%s\n",arr[i].ten);
        }
    }
}

int main(){

    FILE *inp = fopen("Show_screen/INP.TXT", "r"),
        *out = fopen("Show_screen/OUT.TXT", "w");
    
    int N, i;

    fscanf(inp, "%d", &N);
    fgetc(inp);

    struct people arr[N];

    for (i = 0; i < N; i++){
        fgets(arr[i].ten, sizeof(arr[i].ten), inp);
        arr[i].ten[strcspn(arr[i].ten, "\n")] = '\0';

        fscanf(inp, "%d %d", &arr[i].nam_sinh, &arr[i].nam_ket_nap);
        fgetc(inp);
    }
    fclose(inp);

    

    return 0;
}
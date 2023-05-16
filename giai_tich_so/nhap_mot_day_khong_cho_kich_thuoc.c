
#include <stdio.h>
#include<math.h>

void swap(float *a, float *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){

    FILE *inp_file = fopen("Show_screen/INP.TXT", "r"),
        *out_file = fopen("Show_screen/OUT.TXT", "w");

    float sum = 0,
        temp,
        arr[10001];
    int count = 0;

    while (!feof(inp_file)){   
        fscanf(inp_file, "%f", &temp);
        arr[count] = temp;
        sum += temp;
        count++;
    }

    int median = count/2;
    
    for (int i = 0; i < count - 1; i ++){
        for (int j = i + 1; j < count; j++){
            if (arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }

    fprintf(out_file, "Trung binh cong cua day la: %f\n", sum/count);
    fprintf(out_file, "Trung vi cua day la: %f\n", arr[median]);

    fclose(inp_file);
    fclose(out_file);
    return 0;
}
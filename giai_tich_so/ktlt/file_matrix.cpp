
#include <stdio.h>
#include<math.h>

int main(){

    FILE *inp_file = fopen("Show_screen/INP.TXT", "r"),
        *out_file = fopen("Show_screen/OUT.TXT", "w");

    int count = 0, line = 0;
    char arr[10001];

    while (!feof(inp_file)){   
        fscanf(inp_file, "%c", &arr[count]);
        if (arr[count] == '\n'){
            line++;
        }
        count++;
    }
    int number = (count+1)/(line+1);
    fprintf(out_file, "Matrix: \n");

    for (int i = 0; i < count; i++){
        if (i + 1 % number == 0){
            fprintf(out_file, "\n");
        }
        fprintf(out_file,"\t%c", arr[i]);
    }

    fclose(inp_file);
    fclose(out_file);
    return 0;
}
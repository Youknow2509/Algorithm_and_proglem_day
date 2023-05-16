
#include <stdio.h>
#include<math.h>

int main(){

    FILE *inp_file = fopen("Show_screen/INP.TXT", "r"),
        *out_file = fopen("Show_screen/OUT.TXT", "w");

    float sum = 0,
        temp;
    int count = 0;

    while (!feof(inp_file))
    {   
        fscanf(inp_file, "%f", &temp);
        sum += temp;
        count++;
    }
    
    fprintf(out_file, "TBC: %f\n", sum/count);

    return 0;
}
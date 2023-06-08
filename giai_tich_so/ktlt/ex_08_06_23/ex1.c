
#include <stdio.h>
#include <stdlib.h>

int diem_nam_ngoai = 0;
int diem_nam_trong = 0;

struct point{
    float x, y;
};
// Í tưởng nếu điẻm nằm trong đường tròn thì trường hợp điểm trong trên đường tròn cũng thoả mãn//
// nếu í tưởng trên sai sửa lại logic dùng 16 đến 20
void cau1(int n, struct point arr[]){
    int i = 0;
    for (i = 0; i < n; i++){
        float temp = arr[i].x*arr[i].x + arr[i].y*arr[i].y;
        if (temp > 25){
            diem_nam_ngoai++;
        }else{
            diem_nam_trong++;
        }
    }
    printf("So diem nam ben ngoai duong tron la: %d, so diem nam ben trong duong tron la %d\n", diem_nam_ngoai, diem_nam_trong);
}
void cau2(int n, struct point arr[]){
    printf("Cac diem doi xung nhau qua goc toa do la:\n");
    int i = 0, j;
    for (i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            if (arr[i].x + arr[j].x == 0 || arr[i].y + arr[j].y == 0){
                printf("(%f, %f) va (%f, %f);\n", arr[i].x, arr[i].y, arr[j].x, arr[j].y);
            }
        }
    }
}


int main(){

    char name_file[20];
    int n;
        
    scanf("%s", name_file);

    FILE *INP = fopen(name_file, "r"),
        *OUT = fopen("Show_screen/OUT.TXT", "w");

    
    if (INP == NULL) {
        printf("Khong the mo file \n");
        return 1;
    }

    
    fscanf(INP, "%d", &n);
    struct point arr[n];

    int i;
    for (i = 0; i < n; i++){
        fscanf(INP, "%f %f", &arr[i].x, &arr[i].y);
    }
    fclose(INP);
    
    cau1(n, arr);
    cau2(n, arr);

}   
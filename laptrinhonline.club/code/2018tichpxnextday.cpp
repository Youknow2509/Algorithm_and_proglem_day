#include<stdio.h>
int main(){
    int day,month,year;
    scanf("%d/%d/%d",&day,&month,&year);
    if(month==12){
        if(day<31){
            printf("%d/%d/%d",day+1,month,year);
        }
        if(day==31){
            printf("%d/%d/%d",1,1,year+1);
        }
    }
    if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10){
        if(day<31){
            printf("%d/%d/%d",day+1,month,year);
        }
        if(day==31){
            printf("%d/%d/%d",1,month+1,year);
        }
    }
    if(month==4 || month==6 || month==9 || month==11){
        if(day<30){
            printf("%d/%d/%d",day+1,month,year);
        }
        if(day==30){
            printf("%d/%d/%d",1,month+1,year);
        }
    }
    if(month==2){
        if(year%4==0){
            if(day<29){
                printf("%d/%d/%d",day+1,month,year);
            }
            if(day==29){
                printf("%d/%d/%d",1,3,year);
            }
        }
        if(year%4!=0){
            if(day<28){
                printf("%d/%d/%d",day+1,2,year);
            }
            if(day==28){
                printf("%d/%d/%d",1,3,year);
            }
        }
    }
return 0;
}
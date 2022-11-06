
#include <bits/stdc++.h>

using namespace std;

void kt(int a[]){
    int d1=0,d2=0;
    for(int i=0;i<7;i++){
        if(a[i]>a[i+1]){
            d1++;
        }if(a[i]<a[i+1]){
            d2++;
        }
    }
    if(d1==7){
        cout << "GIAM";
    }
    if(d2==7){
        cout << "TANG";
    }
    if(d1!=7&&d2!=7){
        cout << "KHONGBIET";
    }
}

int main(){
    int a[8];
    for(int i=0;i<8;i++){
        cin >> a[i];
    }
    kt(a);
}
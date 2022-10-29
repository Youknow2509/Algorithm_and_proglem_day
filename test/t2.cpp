
#include<bits/stdc++.h>

using namespace std;

int main(){
    double a[6];
    cout << "Nhap 6 so vao chuong trinh"<< endl;
    for( int i = 0; i < 6; i ++) {
        cout << "A[" << i << "] = " << endl;
        cin >> a[i];
    }   

    int c = 0;
    for( int i = 0; i < 6; i ++) {
        if ( a[i] > 0) c ++;
    }
    cout << "Trong 6 so, co: " << c << "so duong";
        


    return 0;
}
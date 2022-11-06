
#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int a, nam , thang, ngay;
    cin >> a;
    nam = a/365;
    thang = ( a - nam*365)/30;
    ngay = a - nam*365 - thang*30;
    cout << nam << " nam" << endl;
    cout << thang << " thang" << endl;
    cout << ngay << " ngay" << endl;
    
    return 0;   
}
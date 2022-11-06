
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int gio, phut, giay, n;
    cin >> n;
    gio = n /3600;
    phut = (n - gio*3600)/60;
    giay = n - gio*3600 - phut*60;
    cout << gio <<":" <<phut << ":" <<giay;

    return 0;   
}
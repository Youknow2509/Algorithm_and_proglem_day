
#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int a, b, c, max, min, mid;
    cin >> a >> b >> c;

    max = a > b ? a : b;
    max = max > c ? max : c;
    min = a < b ? a : b;
    min = min < c ? min : c;
    mid = a + b + c - max - min;
    if ( mid == min || mid == max) cout << "KHONG CO SO O GIUA";
    else cout << mid;

    return 0;   
}

#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int a, b, c;
    cin >> a >> b;
    c = a > b ? a : b; 
    a = a + b - c;
    cout << a <<" " << (int)((c-a)/2);

    return 0;   
}
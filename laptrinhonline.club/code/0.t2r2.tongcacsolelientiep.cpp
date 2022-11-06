
#include <bits/stdc++.h>

using namespace std;

int solve(int a, int b){
    b = b + 1;
    int rs = 0;
    while( a > b){
        if (b % 2 != 0) rs +=b;
        b++;
    }
    return rs;
}

int main(){
    int a, b, c;
    cin >> a >> b;
    c = a > b ? a : b;
    a = a + b - c;
    cout << solve(c, a);
    return 0;   
}
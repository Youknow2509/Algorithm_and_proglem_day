
#include <bits/stdc++.h>

using namespace std;

long solve(int b, int c, long rs){
    if (b > c) return rs;
    if (b % 13 == 0) return solve (b+1, c, rs);
    return solve (b+1, c,(rs + b));
}

int main(){
    int a, b,c;
    long rs = 0;
    cin >> a >> b;
    c = a > b ? a : b;
    b = a + b - c;
    cout << solve(b, c, rs);

    return 0;   
}
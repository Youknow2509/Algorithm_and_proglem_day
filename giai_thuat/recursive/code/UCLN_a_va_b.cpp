
#include <bits/stdc++.h>

using namespace std;

// Xu dung giai thuat Euclid
int solve(int a, int b){
    if (!b) return a;
    return solve(b, a % b);
}

int main(){
    int a, b, sl, sb;
    cin >> a >> b;
    sl = a > b ? a : b;
    sb = a + b - sl;
    cout << solve(sl, sb);   
    return 0;
}
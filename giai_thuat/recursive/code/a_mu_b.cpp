
#include <bits/stdc++.h>

using namespace std;

long long solve(int a, int b){
    if (!b) return 1;
    return a*solve(a, b - 1);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << solve(a, b);   
    return 0;
}
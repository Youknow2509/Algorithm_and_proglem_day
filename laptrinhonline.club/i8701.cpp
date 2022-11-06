
#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    for (int i = 1; i <= 10; i++){
        cout << i << " x " << n << " = " << i*n << endl;
    }
}

int main(){
    int n;
    cin >> n;
    solve(n);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

void solve(long n){
    if ( n == 2) {
        cout << "YES";
        return;
    }
    if ( n <= 1 || n % 2 == 0){
        cout << "NO";
        return;
    }
    for ( long i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

int main(){
    
    long n;
    cin >> n;
    solve(n);
    return 0;
}
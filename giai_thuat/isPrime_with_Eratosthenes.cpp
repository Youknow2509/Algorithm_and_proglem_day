
#include<bits/stdc++.h>

using namespace std;

void fill_true(bool *bl, int n){
    for (int i = 0; i <= n; i++){
        bl[i] = true;
    }
}

bool isPrime(int n){
    bool bl[n];
    fill_true(bl, n);

    if ( n <= 1) return false;
    for (int i = 2; i <= n && bl[i]; i++){
        for (int j = i; j <=n; j ++){
            bl[i*j] = false;
        }
    }
    return bl[n];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
	freopen("OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin >> n;
    
    if (isPrime(n)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

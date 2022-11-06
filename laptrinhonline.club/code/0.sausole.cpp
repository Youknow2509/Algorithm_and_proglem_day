
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, m;
    cin >> n;
    m = (n % 2 != 0) ? n : n + 1;
    for ( int i = m; i <= m + 10; i = i + 2){
        cout << i << endl;
    }
    return 0;   
}
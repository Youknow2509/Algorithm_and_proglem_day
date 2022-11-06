
#include <bits/stdc++.h>

using namespace std;

int main(){
    double a, b;
    cin >> a >> b;
    if ( a == 0 && b == 0){
        cout << "Vo So Nghiem";
        return 0;
    }
    if ( a == 0) cout << "Vo Nghiem";
    else {
        cout << setprecision(3) << fixed << -b/a;
    }
    return 0;   
}
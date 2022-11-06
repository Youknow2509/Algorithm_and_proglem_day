
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ( x1*x2 <= 0 && y1*y2 <= 0){
        cout << "YES";
    }
    else cout << "NO";

    return 0;   
}
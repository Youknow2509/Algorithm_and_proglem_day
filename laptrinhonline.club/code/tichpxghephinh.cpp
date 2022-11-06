
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ( a == c){
        if ( a == b + d) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if ( a == d){
        if ( a == b + c) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if ( b == d){
        if ( b == a + c) cout << "YES";
        else cout << "NO";
        return 0;
    }
    if ( b == c){
        if ( b == a + d) cout << "YES";
        else cout << "NO";
        return 0;
    }
    cout << "NO";
       
}
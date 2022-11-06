
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    long long a[20];
    for ( int i = 0; i < 20; i++){
        cin >> a[i];
    }
    for ( int i = 0; i < 20; i++){
        cout <<"N[" << i <<"] = " << a[19-i] << endl;
    }

    return 0;   
}
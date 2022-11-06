
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int a[10];
    for(int i = 0; i <10; i++){
        cin >> a[i];
        if ( a[i] <= 0) a[i] = 1;
        cout << "X[" << i <<"] = " << a[i] << endl;
    }
    return 0;   
}
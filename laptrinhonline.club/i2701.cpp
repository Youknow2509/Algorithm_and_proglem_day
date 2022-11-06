
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, i = 0, j = 0;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if ( a <= 20 && a >= 10) i++;
        else j++;
    }
    cout << i <<" trong" << endl;
    cout << j <<" ngoai" << endl;


    return 0;   
}
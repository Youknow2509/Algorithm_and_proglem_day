
#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int n, s = 0,tb = 0, j = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n ;i ++){
        cin >> a[i];
        s+=a[i];
    }
    tb = s/n;
    for (int i = 0; i < n ;i ++){
        if(tb > a[i]) j++;
    }
    cout << tb << " " << j;
    

    return 0;   
}
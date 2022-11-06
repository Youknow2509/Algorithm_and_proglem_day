
#include <bits/stdc++.h>

using namespace std;



int main(){
    
    int n,sl = 0, sc = 0, i = 0, j = 0;
    cin >> n;

    while(n--){
        int a;
        cin >> a;
        if (a % 2 == 0){
            sc += a;
            i++;
        }
        else{
            sl +=a;
            j++;
        }
    }
    if (i == 0) i = 1;
    if (j == 0) j = 1;
    cout << (int)sl/j << endl <<(int)sc/i;

    return 0;   
}
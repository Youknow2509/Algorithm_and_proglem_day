
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, bs_2 = 0, bs_3 = 0, bs_4 = 0, bs_5 = 0;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        if (a % 2 == 0) bs_2 ++;
        if (a % 3 == 0) bs_3 ++;
        if (a % 4 == 0) bs_4 ++;
        if (a % 5 == 0) bs_5 ++;
    }
    cout << bs_2 << "  Multiplo(s) de 2" << endl;
    cout << bs_3 << "  Multiplo(s) de 3" << endl;
    cout << bs_4 << "  Multiplo(s) de 4" << endl;
    cout << bs_5 << "  Multiplo(s) de 5" << endl;

    return 0;   
}
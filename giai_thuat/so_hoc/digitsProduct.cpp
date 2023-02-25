// code tìm chữ số tận cùng khác 0 của n!
#include <bits/stdc++.h>

using namespace std;

int digitsProduct(int product)
{
    if (product == 1) return 1;
    if (product == 0) return 10;
    int ans = 0;
    for (int i = 9; i >= 2; i--){
        while(product % i == 0){
            ans = ans * 10 + i;
            product /= i;
        }
    }
    int ans2 = 0;
    while (ans > 0){
        ans2 = ans2 * 10 + ans % 10;
        ans /= 10;
    }
    return (product == 1) ? ans2 : -1;
}


int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("INP.txt", "r", stdin);
    freopen("OUT.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cout << digitsProduct(n) << endl;

    return 0;
}
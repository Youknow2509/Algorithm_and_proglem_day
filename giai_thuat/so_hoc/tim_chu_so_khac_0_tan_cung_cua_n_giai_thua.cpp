// code tìm chữ số tận cùng khác 0 của n!
#include <bits/stdc++.h>

using namespace std;

int lastDigitDiffZero(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
        while ( res % 10 == 0 ) {
            res /= 10;
        }
        res = res % 100;
    }
    while ( res % 10 == 0 ) {
            res /= 10;
    }
    return res % 10;
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
    cout << lastDigitDiffZero(n) << endl;

    return 0;
}
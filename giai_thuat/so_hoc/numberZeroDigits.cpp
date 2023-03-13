
#include<bits/stdc++.h>

using namespace std;

long long numberZeroDigits(long long n)
{
    long long d = 0;
    long long k = 5;
    while (k <= n){
        d += n / k;
        k *= 5;
    }
    return d;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    long long n;
    cin >> n;

    cout << numberZeroDigits(n) << endl;

    return 0;
}


#include<bits/stdc++.h>

using namespace std;

const long long MOD=1e9+7;
long long dp[100000001];

int fibLikeSq(int n)
{
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    dp[4]=3;
    if ( n <= 4) 
        return dp[n];
    for (int i = 5; i <= n; i++)
    {
        dp[i] = (dp[i-1]*dp[i-2] + dp[i-3])%MOD;
    }
    return dp[n];
}
int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;

    cin >> n;

    cout << "Output: " << fibLikeSq(n) << endl;

    return 0;
}



#include<bits/stdc++.h>

using namespace std;

int maximumNonAdj(std::vector<int> arr){
    int n = arr.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return arr[0];
    }
    vector<int> dp(n);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++) {
        dp[i] = max(max(dp[i-1], dp[i-2] + arr[i]), arr[i]);
    }
    return dp[n-1];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int size_arr;

    cin >> size_arr;

    vector<int> vt(size_arr);

    for (int i = 0; i < size_arr; i++){
        cin >> vt[i];
    }

    cout << "Output: " << maximumNonAdj(vt) << endl;

    return 0;
}


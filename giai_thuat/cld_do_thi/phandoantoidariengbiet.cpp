
#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> vt, int n, int k){
    int res = 0,
        i = 0;
    set<int> s;

    while(i <= n - 1){
        for (int j = i; j < n; j++){
            s.insert(vt[j]);
            if (s.size() <= k){
                res++;
            }
            else{
                s.clear();
                break;
            }
        }
        i++;
    }
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, k;
    
    cin >> n >> k;

    vector<int> vt(n);

    for (int i = 0; i < n; i++){
        cin >> vt[i];
    }

    cout << solve(vt, n, k) << endl;

    return 0;
}

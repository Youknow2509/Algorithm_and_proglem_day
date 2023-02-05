
#include<bits/stdc++.h>

using namespace std;

pair<pair<int, int>, int> table_dp(string str, int lenght_str){
    // cap phat bang luu du lieu
    pair<pair<int, int>, int> res;
    pair<int, int> _res;
    int temp = 1;
    int ** table_dp = new int*[lenght_str];
    for (int i = 0; i < lenght_str; i++){
        table_dp[i] = new int[lenght_str];
    }

    for (int i = 0; i < lenght_str; i++){
        for (int j = 0; j < lenght_str; j++){
            if ( i == j) {
                table_dp[i][j] = 1;
            }
            else {
                table_dp[i][j] = 0;
            }
        }
    }

    for (int len = 2; len <= lenght_str; len ++){
        for (int i = 0; i < lenght_str - len + 1; i++){
            int j = i + len - 1;
            if (len == 2 && str[i] == str[j]){
                table_dp[i][j] = 1;
            }
            else if (str[i] == str[j] && table_dp[i+1][j-1] == 1){
                table_dp[i][j] = 1;
            }
            if (table_dp[i][j] && len >= temp){
                temp = len;
                _res.first = i;
                _res.second = j;
                res.first = _res;
                res.second = len;
            } 
        }
    }
    return res;
}

void lps(string str, int lenght_str){
    string res = "";
    pair<pair<int, int>, int> temp = table_dp(str, lenght_str);
    pair<int, int> _temp = temp.first;
    int len = temp.second;
    for (int i = _temp.first; i <= _temp.second; i++){
        res += str[i];
    }
    cout << endl << "Lenght max:  " << len << ", " << res << ". "<< endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("INP.TXT", "r", stdin);
	freopen("OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string str,
        res = "";
    getline(cin, str);
    int lenght_str = str.length();
    
    lps(str, lenght_str);


    return 0;
}

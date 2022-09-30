
// Don't coppy 

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int safePos(int n, int k) {
        // creat vector a = {1, 2, 3, 4, ....., n}
        vector<int> a = creat_vecter(n);
        k = k - 1;
        int index = 0;
        int result = 0;

        solve(index, k, result, a);

        return result;
    }

    vector<int> creat_vecter(int n){
        vector<int> a;
        for ( int i = 1; i <= n; i++){
            a.push_back(i);
        }
        return a;
    }

    void solve(int index, int k, int& result, vector<int>& a){
        // out loop and return result
        if (a.size() == 1) {
            result = a[0];
            return;
        }
        // select element delete, use % -> circle 
        int del_index = (index + k)%a.size();
        a.erase(a.begin() + del_index);
        // loop => result
        solve(del_index, k, result, a); 
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        
        cin>>n>>k;

        Solution ob;
        cout << "Result: " << ob.safePos(n,k) << endl;
    }
    return 0;
}

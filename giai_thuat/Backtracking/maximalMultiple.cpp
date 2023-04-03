#include <bits/stdc++.h>
using namespace std;

int res = -INT_MAX;

void backtracking(std::vector<int> arr, std::vector<int> a, int i, int sum1, int sum2){
    if (i == arr.size() && a.size() != i && a.size() != 0){
        res = max(res, sum1*sum2);
        return;
    }
    a.push_back(arr[i]);
    backtracking(arr, a, i + 1, sum1 + arr[i], sum2);
    a.pop_back();
    backtracking(arr, a, i + 1, sum1, sum2 + arr[i]);
}

int maximalMultiple(std::vector<int> arr){
    vector<int> a;
    backtracking(arr, a, 0, 0, 0);
    return res;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    // 2 4 7
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << maximalMultiple(arr) << endl;

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int longestDecreasingSubsequence(vector<int> arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }
    return maxLen;
}

int main() {
    vector<int> arr = {5, 2, 8, 6, 3, 6, 9, 7};
    cout << longestDecreasingSubsequence(arr) << endl;  // Output: 4
    return 0;
}

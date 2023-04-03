
#include <bits/stdc++.h>

using namespace std;

void backtracking(std::vector<int> arr, int k, int size_arr, int pos, int sum, int& count){
    if (pos == size_arr){
        if (sum == k){
            count++;
        }
        return;
    }

    backtracking(arr, k, size_arr, pos + 1, sum + arr[pos], count);
    backtracking(arr, k, size_arr, pos + 1, sum, count);
}

int combinationSum(std::vector<int> arr, int k){
    int size_arr = arr.size();
    int res = 0;
    backtracking(arr, k, size_arr, 0, 0, res);
    return res;
}
/* 
n = len(arr)
    res = [0]

    def backtrack(start, currSum):
        if currSum == target:
            res[0] += 1
            return
        if currSum > target:
            return
        for i in range(start, n):
            if i > start and arr[i] == arr[i-1]:
                continue
            backtrack(i+1, currSum+arr[i])

    arr.sort()
    backtrack(0, 0)
    return res[0]
 */

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif  

    int size_vector, k;

    cin >> size_vector;

    vector<int> vt(size_vector);

    for (int i = 0; i < size_vector; i++)
        cin >> vt[i];
    
    cin >> k;

    cout << "Output: " << combinationSum(vt, k) << endl;

    return 0;
}
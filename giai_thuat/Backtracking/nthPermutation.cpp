
#include<bits/stdc++.h>

using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

void findPermutation(int n, int k, std::vector<int>& nums, std::vector<int>& result) {
    if (nums.empty()) {
        return;
    }

    int index = k / factorial(n-1);
    int num = nums[index];
    result.push_back(num);
    nums.erase(nums.begin() + index);

    findPermutation(n-1, k % factorial(n-1), nums, result);
}

std::vector<int> nthPermutation(int n, int k) {
    std::vector<int> nums;
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    std::vector<int> result;
    findPermutation(n, k-1, nums, result); // subtract 1 from k to account for 0-indexing

    return result;
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

    std::vector<int> res = nthPermutation(n, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;

    return 0;
}

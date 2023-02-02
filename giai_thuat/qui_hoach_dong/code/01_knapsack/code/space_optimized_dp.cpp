
#include <iostream>

using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    // tạo và khởi tạo mảng dp.
    int dp[W + 1];
    // điều tất cả các giá trị 0 vào mảng dp.
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i < n + 1; i++) {
        for (int w = W; w >= 0; w--) {
            if (wt[i - 1] <= w)
                //tìm giá trị lớn nhất
                dp[w] = max(dp[w],      dp[w - wt[i - 1]] + val[i - 1]);
        }
		/* for (int i = 0; i <= W; i++) cout << dp[i] << "   ";
		cout << endl; */
    }
    return dp[W]; // trả về giá trị lớn nhất của cái túi
}

int main()
{
    int val[] = { 4, 5, 6, 3, 1 };
    int wt[] = { 3, 4, 5, 2, 1};
    int W = 13;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}

// Time Complexity: O(N * W). As redundant calculations of states are avoided.
// Auxiliary Space: O(N * W) + O(N). The use of a 2D array data structure for storing intermediate states and 
// O(N) auxiliary stack space(ASS) has been used for recursion stack.

// Đây là cách tiếp cận từ trên xuống của lập trình động.
#include <bits/stdc++.h>
using namespace std;

// Returns the value of maximum profit
int knapSackRec(int W, int wt[], int val[], int i, int** dp){
	// base condition
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];
	if (wt[i] > W) {
		// Lưu trữ giá trị của ngăn xếp lệnh gọi hàm trong bảng trước khi trả về
		dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
		return dp[i][W];
	}
	else {
		// Lưu trữ giá trị trong một bảng trước khi trả về
		dp[i][W] = max( val[i]  + knapSackRec(W - wt[i], wt, val,i - 1, dp),      knapSackRec(W, wt, val, i - 1, dp));
        // Giá trị trả về của bảng sau khi lưu trữ
		return dp[i][W];
	}
}
// tạo bảng lưu trữ 
int knapSack(int W, int wt[], int val[], int n)
{
	// con trỏ kép để khai báo bảng động
	int** dp;
	dp = new int*[n];
    // vòng lặp để tạo bảng động 2 chiều
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];
    // vòng lặp để điền vào bảng ban đầu với -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRec(W, wt, val, n - 1, dp);
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n);
	return 0;
}

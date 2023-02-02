
#include <bits/stdc++.h>
using namespace std;

//  hàm trả về giá trị lớn hơn của hai số nguyên.
int max(int a, int b) { 
    return (a > b) ? a : b; 
}

// Hàm trả về giá trị lớn nhất khi cái túi có thể chứa được cân nặng W
int knapSack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int> > K(n + 1, vector<int>(W + 1));
    // tạo mảng 2 chiều K để lưu trữ
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]],     K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
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


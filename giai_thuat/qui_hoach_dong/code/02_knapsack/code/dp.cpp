
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
	vector<vector<int> > S(n + 1, vector<int>(W + 1));
    // tạo mảng 2 chiều K để lưu trữ
	for (i = 0; i <= n; i++) {
		for (w = 0; w <= W; w++) {
            S[i][w] = 0;
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
                for (int k = 1; k <= w/wt[i-1];k++){
                    if (k*val[i - 1] + K[i - 1][w - k*wt[i - 1]] > K[i - 1][w]){    
                        K[i][w] = k*val[i - 1] + K[i - 1][w - k*wt[i - 1]];
                        S[i][w] = k;
                    }
                }
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}
	
int main()
{
	int val[] = { 4, 5, 6, 3, 1 };
    int wt[] = { 3, 4, 5, 2, 1};
    int W = 13;
	int n = sizeof(val) / sizeof(val[0]);

	cout << knapSack(W, wt, val, n) << endl;

	return 0;
}


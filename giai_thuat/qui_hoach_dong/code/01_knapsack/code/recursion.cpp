//Time Complexity: O(2ˆN)
//Auxiliary Space: O(N), Stack space required for recursion.

#include <bits/stdc++.h>

using namespace std;
// Hàm trả về giá trị lớn hơn của hai số nguyên.
int max(int a, int b) { return (a > b) ? a : b; }
// Trả về giá trị tối đa có thể đặt trong một chiếc ba lô có dung lượng W.
int knapSack(int W, int wt[], int val[], int n){
	if (n == 0 || W == 0){
		return 0;
    }
	// Nếu trọng lượng của vật phẩm thứ n lớn hơn sức chứa của Ba lô W,
    // thì vật phẩm này không thể được đưa vào giải pháp tối ưu
	if (wt[n - 1] > W){
		return knapSack(W, wt, val, n - 1);
    }
	// Trả lại tối đa hai trường hợp: (1) bao gồm mặt hàng thứ n, (2) không bao gồm
	else{
		return max( (val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1)),		knapSack(W, wt, val, n - 1));
	//              chọn thì tăng giá trị sau thử tiếp các số sau,              nếu không chọn next qua		=> so sánh hai giá trị xem số nào lớn hơn.
    }
}

int main(){
	int val[] = { 60, 120, 100 }; // mảng lưu giá trị.
	int wt[] = { 10, 30, 20 };  // mảng lưu khối lượng của các giá trị.
	int W = 50; // khối lượng của cái túi tối đa.
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack(W, wt, val, n) << endl;
	return 0;
}

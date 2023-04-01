#include <iostream>
#include <vector>
using namespace std;

int max_product = 0;

void findMaxProduct(vector<int>& arr, vector<int>& a, int i, int sum1, int sum2) {

    if (i == arr.size()) { // kết thúc nếu đã duyệt hết mảng arr
        max_product = max(max_product, sum1 * sum2);
        return;
    }

    // thử chia phần tử i vào mảng A
    a.push_back(arr[i]);
    findMaxProduct(arr, a, i+1, sum1+arr[i], sum2); // duyệt các phần tử tiếp theo với mảng A đã được cập nhật
    a.pop_back(); // bỏ phần tử i ra khỏi mảng A

    // thử chia phần tử i vào mảng B
    findMaxProduct(arr, a, i+1, sum1, sum2+arr[i]); // duyệt các phần tử tiếp theo với mảng A ban đầu và mảng B đã được cập nhật
}

int main() {
    vector<int> arr = {4, 2, 7};
    vector<int> a;
    findMaxProduct(arr, a, 0, 0, 0);
    cout << "Max product: " << max_product << endl; 
    return 0;
}

// toạ ma trận lưu các giá trị thành hình xoắn ốc

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate_spiral_matrix(int n) {
    // Khởi tạo ma trận n*n toàn giá trị 0
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    // Khởi tạo các biến giới hạn
    int top = 0, // biên trên
        bottom = n - 1, // biên dưới
        left = 0,   // biên trái
        right = n - 1; // biên phải
    int count = 1; // khởi toạ giá trị điền vào ma trận
    // Đặt giá trị từng phần tử của ma trận theo hình xoắn ốc
    while (count <= n * n) {
        // Đặt giá trị cho hàng trên cùng của phần tử còn lại
        for (int i = left; i <= right; i++) {
            matrix[top][i] = count++;
        }
        top++;
        // Đặt giá trị cho cột bên phải của phần tử còn lại
        for (int i = top; i <= bottom; i++) {
            matrix[i][right] = count++;
        }
        right--;
        // Đặt giá trị cho hàng dưới cùng của phần tử còn lại
        for (int i = right; i >= left; i--) {
            matrix[bottom][i] = count++;
        }
        bottom--;
        // Đặt giá trị cho cột bên trái của phần tử còn lại
        for (int i = bottom; i >= top; i--) {
            matrix[i][left] = count++;
        }
        left++;
    }
    return matrix;
}

int main() {
    int n;
    cout << "Nhap kich thuoc ma tran: ";
    cin >> n;

    vector<vector<int>> matrix = generate_spiral_matrix(n);

    // In ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

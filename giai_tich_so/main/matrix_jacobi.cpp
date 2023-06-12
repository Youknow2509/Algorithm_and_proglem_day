
#include <bits/stdc++.h>

using namespace std;

// Hàm để kiểm tra điều kiện hội tụ
bool isConverged(vector<double>& x, vector<double>& xPrev, double epsilon) {
    // Tính toán sai số Euclide
    double error = 0.0;
    for (int i = 0; i < x.size(); ++i) {
        error += (x[i] - xPrev[i]) * (x[i] - xPrev[i]);
    }
    error = sqrt(error);

    // Kiểm tra điều kiện hội tụ
    if (error < epsilon) {
        return true;
    }
    return false;
}

// Hàm để giải ma trận bằng phương pháp lặp Jacobi
std::vector<double> jacobiMethod(vector<vector<double> >& A, vector<double>& b, double epsilon, int maxIterations) {
    // Kích thước ma trận
    int n = A.size();

    // Khởi tạo nghiệm ban đầu
    std::vector<double> x(n);
    std::vector<double> xPrev(n);
    x[0] = 3;
    x[1] = -2;
    x[2] = 1;
    xPrev[0] = 3;
    xPrev[1] = -2 ;
    xPrev[2] = 1;
    // Biến đếm số lần lặp
    int iterations = 0;

    // Lặp cho đến khi hội tụ hoặc đạt đến số lần lặp tối đa
    while (iterations < maxIterations) {
        // Sao chép nghiệm trước đó
        xPrev = x;

        // Lặp qua từng phần tử của nghiệm
        for (int i = 0; i < n; ++i) {
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sum += A[i][j] * xPrev[j];
                }
            }
            x[i] = (b[i] - sum) / A[i][i];// biểu thức jacobi ....
        }

        // Kiểm tra điều kiện hội tụ
        if (isConverged(x, xPrev, epsilon)) {
            break;
        }

        // Tăng số lần lặp
        iterations++;
    }

    return x;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    int cols, rows; 
    cin >> cols >> rows;
    // Ma trận hệ số A
    vector<vector<double> > A(rows, vector<double>(cols, 0));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> A[i][j]; // nhập dữ liệu ma trận.
        }
    }
    // Ma trận hằng số b
    std::vector<double> b(vector<double>(cols, 0));
    for (int i = 0; i < cols; i++){
        cin >> b[i];
    }
    // Độ chính xác epsilon và số lần lặp tối đa
    double epsilon = 0.00001;
    int maxIterations = 1000000;
    // Giải ma trận bằng phương pháp lặp Jacobi

    std::vector<double> x = jacobiMethod(A, b, epsilon, maxIterations);
    // In nghiệm
    std::cout << "Nghiem cua ma tran: ";
    for (int i = 0; i < x.size(); ++i) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

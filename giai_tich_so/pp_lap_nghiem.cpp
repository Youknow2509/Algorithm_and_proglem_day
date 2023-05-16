#include <bits/stdc++.h>

using namespace std;

// Hàm lặp
double g(double x) {
    // Định nghĩa hàm lặp theo yêu cầu của bài toán
    return (x * x + 3) / 4;
}

// Phương pháp lặp đơn
double phuongPhapLapDon(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iterations = 0;
    
    // Lặp cho đến khi đạt đủ độ chính xác hoặc đạt số lần lặp tối đa
    while (abs(g(x) - x) > epsilon && iterations < maxIterations) {
        x = g(x);
        iterations++;
    }
    
    // Kiểm tra điều kiện hội tụ
    if (fabs(g(x) - x) <= epsilon) {
        std::cout << "Phuong trinh co nghiem gan dung la: " << x << std::endl;
        std::cout << "Sau " << iterations << " lan lap." << std::endl;
    } else {
        std::cout << "Khong tim thay nghiem sau " << maxIterations << " lan lap." << std::endl;
    }
    
    return x;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif  

    double x0,         // Điểm khởi đầu
        epsilon; // Độ chính xác mong muốn
    int maxIterations; // Số lần lặp tối đa

    cin >> x0 >> epsilon >> maxIterations;

    phuongPhapLapDon(x0, epsilon, maxIterations);

    return 0;
}

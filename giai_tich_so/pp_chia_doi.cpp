#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    return x*x*x - x - 1; // Ví dụ hàm số x^2 - 4
}

double bisection(double a, double b, double eps) {
    double c = (a + b) / 2; // Lấy điểm giữa của đoạn [a, b]
    while (abs(f(c)) > eps) { // Nếu giá trị hàm số tại c không đạt độ chính xác yêu cầu
        if (f(a) * f(c) < 0) b = c; // Nếu f(a) và f(c) trái dấu thì nghiệm nằm trên đoạn [a, c]
        else a = c; // Ngược lại, nghiệm nằm trên đoạn [c, b]
        c = (a + b) / 2; // Lấy lại điểm giữa của đoạn mới
    }
    return c; // Trả về nghiệm với độ chính xác eps
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif  
    
    double a, b, eps; // Ví dụ tìm nghiệm của hàm số trên đoạn [1, 2] với độ chính xác 0.00001
    cin >> a >> b >> eps;
    cout << f(1)*f(2) << endl;
    cout << "Nghiem cua ham so la: " << bisection(a, b, eps) << endl;
    return 0;
}

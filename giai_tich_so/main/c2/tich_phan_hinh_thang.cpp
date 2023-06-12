
#include <bits/stdc++.h>

using namespace std;

double integrate(double (*f)(double), double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double x0 = a + i * h;
        double x1 = a + (i + 1) * h;
        double y0 = f(x0);
        double y1 = f(x1);

        sum += (y0 + y1) * h / 2.0;
    }

    return sum;
}

// Hàm số mẫu để tính tích phân
double sampleFunction(double x) {
    return abs(pow(sin(x), 4) + pow(x, 3)); // Ví dụ: hàm số x^2
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double a; // Giới hạn dưới của đoạn tích phân
    double b; // Giới hạn trên của đoạn tích phân
    int n;   // Số lượng đoạn hình thang

    cin >> a >> b >> n;

    double integral = integrate(sampleFunction, a, b, n);

    std::cout << "Tích phân của hàm số từ " << a << " đến " << b << " là: " << integral << std::endl;

    return 0;
}

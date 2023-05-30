
#include <bits/stdc++.h>

using namespace std;

double integrate(double (*f)(double), double a, double b, int n) {
    if (n % 2 != 0) {
        std::cout << "Số lượng đoạn phải là một số chẵn." << std::endl;
        return 0.0;
    }

    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * (i % 2 == 0 ? 2 : 4) * f(x);
    }

    return sum * h / 3.0;
}

// Hàm số mẫu để tính tích phân
double sampleFunction(double x) {
    return pow(x, 2); // Ví dụ: hàm số x^2
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double a; // Giới hạn dưới của đoạn tích phân
    double b; // Giới hạn trên của đoạn tích phân
    int n;   // Số lượng đoạn Simpson (phải là một số chẵn)

    cin >> a >> b >> n;

    double integral = integrate(sampleFunction, a, b, n);

    std::cout << "Tích phân của hàm số từ " << a << " đến " << b << " là: " << integral << std::endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    // Định nghĩa hàm f(x) của phương trình
    return pow(3, x) - 5*x - 8;
}

double derivative(double x) {
    // Định nghĩa hàm f'(x) (đạo hàm của f(x))
    return pow(3, x)*std::log(3) / std::log(std::exp(1.0)); - 5;
}

double secantMethod(double x0, double x1, double epsilon, int maxIterations) {
    double x2;
    int iteration = 0;

    while (std::abs(x1 - x0) >= epsilon && iteration < maxIterations) {
        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        x0 = x1;
        x1 = x2;

        iteration++;
    }

    std::cout << "Số lần lặp: " << iteration << std::endl;

    return x2;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double x0;       // Điểm ban đầu x0
    double x1;       // Điểm ban đầu x1
    double epsilon;  // Sai số epsilon
    int maxIterations; // Số lần lặp tối đa

    cin >> x0 >> x1 >> epsilon >> maxIterations;

    double root = secantMethod(x0, x1, epsilon, maxIterations);

    std::cout << "Nghiệm của phương trình: " << root << std::endl;

    return 0;
}

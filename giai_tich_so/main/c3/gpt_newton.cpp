
#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    // Định nghĩa hàm f(x) của phương trình
    return x * x - 4;
}

double derivative(double x) {
    // Định nghĩa hàm f'(x) (đạo hàm của f(x))
    return 2 * x;
}

double newtonMethod(double x0, double epsilon, int maxIterations) {
    double x = x0;
    int iteration = 0;

    while (std::abs(f(x)) >= epsilon && iteration < maxIterations) {
        double delta_x = f(x) / derivative(x);
        x = x - delta_x;
        iteration++;
    }

    std::cout << "Số lần lặp: " << iteration << std::endl;

    return x;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double x0;       // Điểm ban đầu x0
    double epsilon;  // Sai số epsilon
    int maxIterations; // Số lần lặp tối đa

    cin >> x0 >> epsilon >> maxIterations;

    double root = newtonMethod(x0, epsilon, maxIterations);

    std::cout << "Nghiệm của phương trình: " << root << std::endl;

    return 0;
}

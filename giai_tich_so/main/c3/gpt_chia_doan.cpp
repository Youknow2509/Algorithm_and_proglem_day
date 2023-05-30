
#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    // Định nghĩa hàm f(x) của phương trình
    return x * x - 4;
}

double bisectionMethod(double a, double b, double epsilon) {
    if (f(a) * f(b) >= 0) {
        std::cout << "Không thể áp dụng phương pháp chia đoạn trên đoạn [a, b]." << std::endl;
        return NAN;
    }

    double c;
    int iteration = 0;

    while ((b - a) >= epsilon) {
        c = (a + b) / 2;

        if (f(c) == 0.0) {
            break;
        }
        else if (f(c) * f(a) < 0) {
            b = c;
        }
        else {
            a = c;
        }

        iteration++;
    }

    std::cout << "Số lần lặp: " << iteration << std::endl;

    return c;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double a;       // Điểm đầu của đoạn [a, b]
    double b;       // Điểm cuối của đoạn [a, b]
    double epsilon;  // Sai số epsilon

    cin >> a >> b >> epsilon;

    double root = bisectionMethod(a, b, epsilon);

    std::cout << "Nghiệm của phương trình: " << root << std::endl;

    return 0;
}

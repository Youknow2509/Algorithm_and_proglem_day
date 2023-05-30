
#include <bits/stdc++.h>

using namespace std;

double derivative(double (*f)(double), double x, double h) {
    double fx = f(x);
    double fxph = f(x + h);
    double df = (fxph - fx) / h;
    return df;
}

// Hàm số mẫu để tính đạo hàm gần đúng
double sampleFunction(double x) {
    return pow(x, 3); // Ví dụ: hàm số x^3
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    double x; // Giá trị x để tính đạo hàm tại x 
    cin >> x;

    double h = 0.0001; // Độ dài bước
    double df = derivative(sampleFunction, x, h);


    cout << "Đạo hàm gần đúng tại x = " << x << " là: " << df << std::endl;

    return 0;
}

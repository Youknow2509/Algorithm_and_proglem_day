#include <bits/stdc++.h>

using namespace std;

double f(double x) {
    // Hàm cần tính tích phân
    return x*x*pow(M_E,x)/(6*x*x+11);
}

std::vector<double> calculate_divided_differences(std::vector<double>& x, std::vector<double>& y) {
    // Tính đa thức các hiệu phân chia
    std::vector<double> f;
    f.push_back(y[0]);
    for (int j = 1; j < x.size(); j++) {
        for (int i = x.size() - 1; i >= j; i--) {
            y[i] = (y[i] - y[i - 1]) / (x[i] - x[i - j]);
        }
        f.push_back(y[j]);
    }
    return f;
}

double newton_interpolation(double x, std::vector<double>& xi, std::vector<double>& fi) {
    // Tính giá trị nội suy của f(x) tại x sử dụng phương pháp Newton
    std::vector<double> f = calculate_divided_differences(xi, fi);
    double result = f[0];
    double p = 1.0;
    for (int i = 1; i < xi.size(); i++) {
        p *= (x - xi[i - 1]);
        result += f[i] * p;
    }
    return result;
}

double simpson(double a, double b, int n) {
    // chú ý n phải chẵn
    // chú ý sửa hàm tính giá trị tại điểm theo đề bài
    double h = (b - a) / n;
    double sum = f(a) + f(b);
    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }
    for (int i = 2; i < n; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }
    return sum * h / 3.0;
}

double hinh_thang(double a, double b, int n) {
    // chú ý sửa hàm tính giá trị tại điểm theo đề bài
    double h = (b-a)/n;
    double sum = (f(a) + f(b))/2.0;
    for (int i = 1; i < n; i++) {
        double x = a + i*h;
        sum += f(x);
    }
    return sum*h;
}

double f_derivative(double x) {
    // Tính đạo hàm của f(x) tại x
    double h = 0.0001; // Độ chính xác của xấp xỉ đạo hàm
    return (f(x + h) - f(x - h)) / (2 * h);
}

double bisection(double a, double b, double eps) {
    double c = (a + b) / 2; // Lấy điểm giữa của đoạn [a, b]
    while (abs(f(c)) > eps) { // Nếu giá trị hàm số tại c không đạt độ chính xác yêu cầu
        if (f(a) * f(c) < 0) b = c; // Nếu f(a) và f(c) trái dấu thì nghiệm nằm trên đoạn [a, c]
        else a = c; // Ngược lại, nghiệm nằm trên đoạn [c, b]
        c = (a + b) / 2; // Lấy lại điểm giữa của đoạn mới
    }
    return c; // Trả về nghiệm với độ chính xác eps
    // Ví dụ tìm nghiệm của hàm số trên đoạn [a, b] với độ chính xác eps
}
int main() {

    
    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif  

    /* 
    double a; // Điểm bắt đầu đoạn
    double b; // Điểm kết thúc đoạn
    int n; // Số đoạn

    cin >> a >> b >> n;

    double result = simpson(a, b, n);
    std::cout << "Tich phan cua f(x) tu " << a << " den " << b << " la: " << result << std::endl;
    */


    // dùng cái nào tắt cái kia

    
    int kich_thuoc_bang_noi_suy;

    cin >> kich_thuoc_bang_noi_suy;

    std::vector<double> xi(kich_thuoc_bang_noi_suy), // Các điểm x để nội suy
        fi(kich_thuoc_bang_noi_suy); // cac gia tri f(x) 
    for (int i = 0; i < kich_thuoc_bang_noi_suy; i++) {
        double x, y;
        cin >> x >> y;
        xi[i] = x;
        fi[i] = y;
    }
    double xo; // Điểm cần nội suy

    cin >> xo; // gia tri can noi suy

    double result = newton_interpolation(xo, xi, fi);
    std::cout << "f(" << xo << ") = " << result << std::endl;
    
    return 0;
}

/* 
 c1 0.470041
    7.64492
    -9.54
 */
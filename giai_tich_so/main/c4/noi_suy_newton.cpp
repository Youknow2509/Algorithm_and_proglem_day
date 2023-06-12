
#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x;
    double y;
};

double dividedDifference(int start, int end, const std::vector<Point>& points) {
    if (start == end) {
        return points[start].y;
    } else {
        return (dividedDifference(start + 1, end, points) - dividedDifference(start, end - 1, points)) /
               (points[end].x - points[start].x);
    }
}

double interpolateNewton(double x, const std::vector<Point>& points) {
    double result = 0.0;

    for (size_t i = 0; i < points.size(); ++i) {
        double term = dividedDifference(0, i, points);

        for (size_t j = 0; j < i; ++j) {
            term *= (x - points[j].x);
        }

        result += term;
    }

    return result;
}

int main() {
    
    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

   int n; // Co n diem

    cin >> n;

    std::vector<Point> points(n);

    for (int i = 0; i < n; i++){
        cin >> points[i].x >> points[i].y;
    }

    double x; // Giá trị x cần nội suy

    cin >> x;

    double interpolatedValue = interpolateNewton(x, points);

    std::cout << "Giá trị nội suy tại x = " << x << " là: " << interpolatedValue << std::endl;

    return 0;
}

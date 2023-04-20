#include <iostream>
using namespace std;

void creat_table(vector<double> X, int n, vector<vector<double> > &res){
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
            res[i][j] = (res[i-1][j+1] - res[i-1][j])/(X[i+j] - X[j]);
        }
    }
}

void print_table_newton(vector<vector<double> > tb_n, int n){
    cout << "Table: " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i; j++){
            cout << tb_n[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

double f (double x, vector<vector<double> >tb, vector<double> X,int n){
    double res = tb[0][0],
        temp = 1;
    for (int i = 1; i < n; i++){
        temp *= (x - X[i - 1]);
        res += temp*tb[i][0];
    }
    return res;
}

double f_(double x, vector<vector<double> >tb, vector<double> X,int n)  {
    double h = 0.0000001;
    return (f(x + h, tb, X, n) - f(x - h, tb, X, n)) / (2*h);
}

string f_x(vector<vector<double> >tb, vector<double> X,int n){
    string res = to_string(tb[0][0]),
        temp = "(x - " + to_string(X[0]) + ")";
    for (int i = 1; i < n; i++){
        res += " + " + to_string(tb[i][0]) + "*" +temp;
        temp += "*(x - " + to_string(X[i]) + ")";
    }
    return res;
}

double tich_phan_a_den_b(double a, double b, vector<vector<double> >tb, vector<double> X,int n){
    int h = 10000;
    double d = (b - a)/h,
        res  = f(a,tb, X, n) + f(b,tb, X, n);
    for (double i = 1; i < h; i ++){
        double x = a + i*d;
        res += 2*f(x,tb, X, n);
    }
    return (d/2)*res;
}

double tinh_so_phan_doan_thoa_man(vector<vector<double> >tb, int n, double a, double b, double sai_so){
    // Error = -((b-a)^3/(12*n^2)) * f''(ξ)
}

int main() {
/* 
5
0 1
2 3
3 2
5 5
6 6
1
1
3
 */
    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif  
    int n;
    double _x;

    cin >> n;

    vector<double> X(n),
        Y(n);
    vector<vector<double> >table_newton(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        table_newton[0][i] = Y[i];
    }

    cin >> _x;

    creat_table(X, n, table_newton);
    //print_table_newton(table_newton, n);
    cout << "F(x) = " << f_x(table_newton, X, n) << endl;
    cout << "F(" << _x << ") = " << f(_x, table_newton, X, n) << endl;
    cout << "F'(" << _x << ") = " << f_(_x, table_newton, X, n) << endl;
    double a, b;
    cin >> a >> b;
    cout << "Tich phan cua F(x) tu a den b = " << tich_phan_a_den_b(a, b, table_newton, X, n) << endl;

    return 0;
}

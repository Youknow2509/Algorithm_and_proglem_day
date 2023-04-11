
#include<bits/stdc++.h>

using namespace std;

vector<vector<double> > creat_table(vector<double>X, vector<double>Y, double _x){
    int n = X.size();
    vector<vector<double> >res(n, vector<double>(n));
    for (int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j){
                res[i][j] = _x - X[i];
            }
            else{
                res[i][j] = X[i] - X[j];
            }
        }
    }
    return res;
}

void print_table_lagrange(vector<vector<double> > tb_l,  double _x){
    cout << "Bang lagrange khi x = " << _x << endl;
    int n = tb_l.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << tb_l[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

double solve(vector<vector<double> >table_lagrange, double _x, vector<double> Y){
    int n = table_lagrange.size();
    vector<double> D(n+1, 1);
    double res = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            D[i] *= table_lagrange[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j){
                D[n] *=table_lagrange[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++){
        res += Y[i]/D[i];
    }
    return D[n]*res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    
    
    int n;
    double _x;

    cin >> n;

    vector<double>X(n),
        Y(n+1);
    
    vector<vector<double> >table_lagrange(n, vector<double>(n));

    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
    }

    cin >> _x;

    table_lagrange = creat_table(X, Y, _x);

    print_table_lagrange(table_lagrange, _x);
// f(-x) = 
    cout << "F(x) = F(" << _x << ") = " << solve(table_lagrange, _x, Y) << endl; 

    return 0;
}

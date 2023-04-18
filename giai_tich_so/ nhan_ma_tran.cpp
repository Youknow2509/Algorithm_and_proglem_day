
#include<bits/stdc++.h>

using namespace std;

void nhap(vector<vector<double> > &A, double m, double n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> A[i][j];
        }
    }
}
void in(vector<vector<double> > A, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void tong_mt(vector<vector<double> > &res, vector<vector<double> > A, vector<vector<double> > B, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            res[i][j] = A[i][j] + B[i][j];
        }
    }
}

void nhan_mt(vector<vector<double> > &res, vector<vector<double> > A, vector<vector<double> > B, int m, int n, int p){
    // A[m][n], B[n][p], C[m][p]
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            for (int z = 0; z < n; z++){
                res[i][j] += A[i][z]*B[z][j];
            }
        }
    }
}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    // ma tran kich thuoc m*n: m hang, n cot
    int m , n, p;
    cin >> m >> n;
    vector<vector<double> > A(m, vector<double>(n));
    nhap(A, m, n);
    vector<vector<double> > B(n, vector<double>(m));
    nhap(B, n, m);
    vector<vector<double> > C(m, vector<double>(m));
    nhan_mt(C, A, B, m, n, m);
    in(C, m, m);
    return 0;
}

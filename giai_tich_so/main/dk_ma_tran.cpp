
#include <bits/stdc++.h>

using namespace std;

// Ham tra ve ma tran nghich dao
vector<vector<double> > inverseMatrix(vector<vector<double> > matrix) {
        int n = matrix.size();
        vector<vector<double> > identity(n, vector<double>(n, 0.0));
        for (int i = 0; i < n; i++) {
            identity[i][i] = 1.0;
        }
        // Gán ma trận nhận kết quả ban đầu là ma trận đơn vị
        vector<vector<double> > result = identity;
        // Biến đổi ma trận gốc thành ma trận đường chéo
        for (int i = 0; i < n; i++) {
            double pivot = matrix[i][i];
            // Chia hàng i cho pivot để có phần tử chéo là 1
            for (int j = 0; j < n; j++) {
                matrix[i][j] /= pivot;
                result[i][j] /= pivot;
            }
            // Loại bỏ các phần tử khác 0 bên dưới phần tử chéo
            for (int j = 0; j < n; j++) {
                if (j != i) {
                    double factor = matrix[j][i];
                // Trừ hàng i nhân với factor từ các hàng khác
                    for (int k = 0; k < n; k++) {
                        matrix[j][k] -= factor * matrix[i][k];
                        result[j][k] -= factor * result[i][k];
                    }
                }
            }
        }
    return result;
}

class dk_ma_tran_hang_ngang {
public:
    double sum_Row_max(vector<vector<double> > matrix){
        int numRows = matrix.size(),
            numCols = matrix[0].size();
        double res = DBL_MIN;
        for (int i = 0; i < numRows; i++){
            double temp = 0;
            for (int j = 0; j < numCols; j++){
                temp += abs(matrix[i][j]);
            }
            res = max(res, temp);
        }
        return res;
    }
    void solve (vector<vector<double> > matrix){
        double a = sum_Row_max(matrix),
            b = sum_Row_max(inverseMatrix(matrix));
        cout << "Điều kiện tra trận theo hàng ngang là: " << a << " * " << b << " = " << a*b << endl;
    }
};

class dk_ma_tran_hang_doc {
public:
    double sum_Col_max(vector<vector<double> > matrix){
        int numRows = matrix.size(),
            numCols = matrix[0].size();
        double res = DBL_MIN;
        for (int i = 0; i < numRows; i++){
            double temp = 0;
            for (int j = 0; j < numCols; j++){
                temp += abs(matrix[j][i]);
            }
            res = max(res, temp);
        }
        return res;
    }
    void solve (vector<vector<double> > matrix){
        double a = sum_Col_max(matrix),
            b = sum_Col_max(inverseMatrix(matrix));
        cout << "Điều kiện tra trận theo hàng dọc là: " << a << " * " << b << " = " << a*b << endl;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    int numRows, numCols;

    cin >> numRows >> numCols; // nhập số hàng số cột.

    vector<vector<double> > matrix(numRows, vector<double>(numCols, 0));

    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < numCols; j++){
            cin >> matrix[i][j]; // nhập dữ liệu ma trận.
        }
    }

    cout << "Chọn 1 để tính điều kiện theo ma trận dọc, 2 để tính điều kiện tra trận ngang ( vo cung ): " << endl;

    int chosses; cin >> chosses;

    if (chosses == 1){
        dk_ma_tran_hang_doc st;
        st.solve(matrix);
    }
    else {
        dk_ma_tran_hang_ngang st;
        st.solve(matrix);
    }

    return 0;
}
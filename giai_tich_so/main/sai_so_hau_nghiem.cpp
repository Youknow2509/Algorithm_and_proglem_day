#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính chuẩn vô cùng của vector
double infinityNorm(double *vector, int size) {
    double maxNorm = 0.0;

    for (int i = 0; i < size; i++) {
        double absValue = abs(vector[i]);
        if (absValue > maxNorm) {
            maxNorm = absValue;
        }
    }

    return maxNorm;
}

// Hàm tính sai số hậu nghiệm và chuẩn vô cùng
void computeBackwardError(double **matrix, double *vector, double *solution, int size) {
    // Tính sai số hậu nghiệm
    double *residual = new double[size];
    for (int i = 0; i < size; i++) {
        double sum = 0.0;
        for (int j = 0; j < size; j++) {
            sum += matrix[i][j] * solution[j];
        }
        residual[i] = vector[i] - sum;
    }

    // Tính chuẩn vô cùng của sai số hậu nghiệm
    double errorNorm = infinityNorm(residual, size);

    cout << "Sai số hậu nghiệm: ";
    for (int i = 0; i < size; i++) {
        cout << residual[i] << " ";
    }
    cout << endl;

    cout << "Chuẩn vô cùng của sai số hậu nghiệm: " << errorNorm << endl;

    delete[] residual;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/INP.TXT", "r", stdin);
    freopen("/Users/v/code/Algorithm_and_proglem_day/giai_tich_so/main/Show_screen/OUT.TXT", "w", stdout);
    #endif

    // Khởi tạo ma trận và vector
    int size;
    cout << "Nhập kích thước ma trận/véc-tơ: ";
    cin >> size;

    // Cấp phát động bộ nhớ cho ma trận và vector
    double **matrix = new double*[size];
    double *vector = new double[size];
    double *solution = new double[size];

    cout << "Nhập các phần tử của ma trận:\n";
    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
        for (int j = 0; j < size; j++) {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "Nhập các phần tử của vector:\n";
    for (int i = 0; i < size; i++) {
        cout << "vector[" << i << "]: ";
        cin >> vector[i];
    }

    cout << "Nhập các phần tử của vector giải:\n";
    for (int i = 0; i < size; i++) {
        cout << "solution[" << i << "]: ";
        cin >> solution[i];
    }

    // Tính sai số hậu nghiệm và chuẩn vô cùng
    computeBackwardError(matrix, vector, solution, size);

    // Giải phóng bộ nhớ
    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] vector;
    delete[] solution;

    return 0;
}

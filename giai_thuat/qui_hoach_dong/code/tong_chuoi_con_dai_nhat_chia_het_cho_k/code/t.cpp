#include <iostream>

using namespace std;

int arr[10001], F[10001][10001];
void taoBangPhuongAn(int size_arr, int k) {
    int r;
    for (int v = 0; v <= k-1; v++) 
        F[1][v] = (arr[v]%k == v) ? 1 : 0; 
    for (int i = 2; i <= size_arr; i++){
        for (int v = 0; v <= k-1; v++) { 
            r = arr[i]%k;
            F[i][v] = F[i-1][v];
            if (v == r && F[i][v] <= F[i-1][0]){
                F[i][v] = F[i-1][0] + 1;
            }
            else if (F[i-1][(v - r + k)%k] >0 && F[i][v] <= F[i-1][(v - r + k)%k]){
                F[i][v] = F[ i -1][(v - r + k)%k] + 1;
            }
        }
    }
}

int main() {
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    int size_arr,
        k,
        res;
    cin >> size_arr;
    for (int i = 0; i < size_arr; i++)
        cin >> arr[i];
    cin >> k;
    taoBangPhuongAn(size_arr, k);
    for (int i = 0; i < size_arr + 1; i++){
        for (int j = 0; j < k; j++){
            cout << F[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
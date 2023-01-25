
#include <bits/stdc++.h>

using namespace std;

// Tạo biến d để đánh dấu các số đã xuất hiện.
bool ok[1001];
// Tạo mảng a để lưu các giá trị để ghép thành chuỗi.
int a[1001];

void in_chuoi(int n){
    for (int i = 1; i <= n; i++) cout << a[i];
    cout << " ";
}

void solve(int k, int n){
    for (int i = 1; i <= n; i++){
        // check xem số đã xuất hiện chưa, nếu chưa thì thêm vào chuỗi, nếu rồi thì next qua.
        if (ok[i]){
            // cho kí tự thứ k vào số vào chuỗi
            a[k] = i;
            if ( k == n){
                // đã ghép đủ số kí tự vào chuỗi, in ra màn hình chuỗi.
                in_chuoi(n);
            }
            else{
                ok[i] = false;
                solve(k+1, n);
                ok[i] = true;
            }
        }
    }
}

void danh_dau(int n){
    for (int i = 1; i <= n; i++){
        ok[i] = true;
    }
    // chúng ta khởi tạo true là số chưa được xuất hiện, còn false là đã xuất hiện.
}

int main(){
    int n;
    cin >> n;
    // tạo mảng đánh dấu.
    danh_dau(n);
    // ghép chuỗi và in chuỗi bằng đệ qui
    solve(1, n);

    return 0;
}
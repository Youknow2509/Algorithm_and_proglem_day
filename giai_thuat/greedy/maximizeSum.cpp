
#include <bits/stdc++.h>

using namespace std;

int maximizeSum(std::vector<int> arr){

    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int mid = n / 2;

    // Tìm vị trí trung tâm
    if (n % 2 == 0) {
        mid--;
    }

    // Sắp xếp các phần tử của mảng mới
    vector<int> arr_new;
    for (int i = mid + 1, j = mid; i < n || j >= 0; i++, j--) {
        if (i < n) {
            arr_new.push_back(arr[i]);
        }
        if (j >= 0) {
            arr_new.push_back(arr[j]);
        }
    }

    // Tính tổng lớn nhất của mảng mới
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr_new[i] - arr_new[(i+1)%n]);
    }

    return sum;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int size_arr;
    
    cin >> size_arr;

    vector<int> vt(size_arr);

    for (int i = 0; i < size_arr; i++){
        cin >> vt[i];
    }

    cout << "Output: " << maximizeSum(vt) << endl;

    return 0;
}

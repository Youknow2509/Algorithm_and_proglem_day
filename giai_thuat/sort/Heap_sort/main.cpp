
#include<bits/stdc++.h>

using namespace std;

template <typename T>
void creatHeap(vector<T>&vt, int index, int n){
    int largest = index;
    int left = 2 * index + 1,
        right = 2 * index + 2;
    if (left < n && vt[left] > vt[largest])
        largest = left;
    if (right < n && vt[right] > vt[largest])
        largest = right;
    // Xử dụng hai if và khong if else để tìm max trong hai nút lá 
    if (largest != index) {
        swap(vt[index], vt[largest]);
        creatHeap(vt, largest, n);
    }
}

template <typename T> void heapSort(vector<T>& vt, int n){
    // Biến đổi thành cây Max heap lần lượt từ dưới lên
    for (int i = (n - 1)/2; i >= 0; i--){
        creatHeap(vt, i, n); // Khởi tạo cây từ phần tử i đến N
    }
    
    for (int i = n - 1; i > 0; i--) {
        swap(vt[0], vt[i]);
        creatHeap(vt, 0, i);
    }
}

template <typename T> void show_arr(vector<T> vt){
    int n = vt.size();
    for (int i = 0; i < n; i++){
        cout << vt[i] << " ";
    }
    cout << endl;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("terminal/inp.txt", "r", stdin);
    freopen("terminal/out.txt", "w", stdout);
    #endif 

    int size_vt; cin >> size_vt;
    vector<int> vt(size_vt);
    for (int i = 0; i < size_vt; i++){
        cin >> vt[i];
    } 

    heapSort(vt, size_vt);

    show_arr(vt);

    return 0;
}
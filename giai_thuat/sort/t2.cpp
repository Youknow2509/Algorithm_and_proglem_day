
#include <iostream>

using namespace std;

void swap(int *a1, int *a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

int partition(int *a, int s, int e){
    int pivot = a[e],
        temp = s;
    for (int i = s; i < e; i++){
        if (pivot > a[i]){
            swap(&a[i], &a[temp]);
            temp++;
        }
    }
    swap(&a[temp], &a[e]);
    return temp;
}

void quick_sort(int *a, int s, int e){
    if (s < e){
        int pi = partition(a, s, e);
        quick_sort(a, s, pi - 1);
        quick_sort(a, pi+ 1, e);
    }
}

int solve(int *arr, int size_arr, int k){
    int res = 0;
    for (int i = 1; i < size_arr; i++){
        if (arr[i] - arr[i-1] > k){
            res++;
        }
    }
    return res + 1;
}

int main(){
    int size_arr, k;
    cin >> size_arr;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++){
        cin >> arr[i];
    }
    cin >> k;
    quick_sort(arr, 0, size_arr - 1);
    cout << solve (arr, size_arr, k) << endl;
    return 0;
}

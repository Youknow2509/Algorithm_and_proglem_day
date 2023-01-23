#include <iostream>
#include <math.h>

using namespace std;

void swap(int *a1, int *a2){
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

int partition(int* arr, int start, int end){
    int pivot = arr[end],
        temp = start;
    for (int i = start; i < end; i++){
        if (arr[i] < pivot){
            swap(&arr[i], &arr[temp]);
            temp++;
        }
    }
    swap(&arr[end], &arr[temp]);
    return temp;
}

void quick_sort(int* arr, int start, int end){
    if (start < end){
        int pi = partition(arr, start, end);
        quick_sort(arr, start, pi - 1);
        quick_sort(arr, pi + 1, end);
    }
}

bool check(int n){
    int k = (int) sqrt(n);
    return k*k == n;
}

void solve(int *arr, int size_arr){
    int size_arr_temp = 0,
        arr_2[size_arr];
    for (int i = 0; i < size_arr; i++){
        if (check(arr[i])){
            arr_2[size_arr_temp] = arr[i];
            size_arr_temp = size_arr_temp + 1;
        }
    }
    if (!size_arr_temp){
        cout << "NULL" << endl;
    }
    else{
        cout << arr_2[0] << " ";
        for (int i = 1; i < size_arr_temp; i++){
            if (arr_2[i] != arr_2[i-1]){
                cout << arr_2[i] << " ";
            }
        }
    }
}

int main(){
    // input
    int size_arr;
    cin >> size_arr;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++){
        cin >> arr[i];
    }
    // solve
    quick_sort(arr, 0, size_arr - 1);
    solve(arr, size_arr);
    return 0;
}

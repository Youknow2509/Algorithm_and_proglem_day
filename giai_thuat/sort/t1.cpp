// Tần số xuất hiện 
#include <bits/stdc++.h>

using namespace std;

void swap(int *arr1, int *arr2){
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
}

int partition(int *arr, int start, int end){
    int pivot = arr[end];
    int elm_high = start;
    for (int i = start; i < end; i++){
        if (arr[i] < pivot){
            swap(&arr[i], &arr[elm_high]);
            elm_high++;
        }
    }
    swap(&arr[elm_high], &arr[end]);
    return elm_high;
}

void Quick_Sort_Array(int *arr, int start, int  end){
    if (start < end){
        int pi = partition(arr, start, end);
        Quick_Sort_Array(arr, start, pi - 1);
        Quick_Sort_Array(arr, pi + 1, end);
    }
}

void Solve(int *arr, int size_arr){
    //Quick_Sort_Array(arr, 0, size_arr - 1);
    int count = 1;
    for (int i = 1; i < size_arr; i++){
        if (arr[i] == arr[i-1]){
            count++;
        }
        else{
            cout << arr[i-1] << " " << count << "; ";
            count = 1;
        }
    }
    cout << arr[size_arr-1] << " " << count << "; ";
}

int main(){
    int size_arr;
    cin >> size_arr;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++)
        cin >> arr[i];
    // sort arr with quick sort.
    Quick_Sort_Array(arr, 0, size_arr - 1);
    Solve(arr, size_arr);
    return 0;
}
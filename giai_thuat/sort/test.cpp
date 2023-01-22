
#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b)
    {
        int t = *a;
        *a = *b;
        *b = t;
    }

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void Quick_Sort(int *arr, int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        Quick_Sort(arr, low, pi - 1);
        Quick_Sort(arr, pi + 1, high);
    }
}

int Solve(int *arr, int size_arr){
    if (arr[0] > 0) return 0;
    for (int i = 1; i < size_arr; i++){
        if (arr[i] - arr[i-1] > 1) return arr[i-1] + 1;
    }
    return arr[size_arr-1] + 1;
}
int main(){
    int size_arr;
    cin >> size_arr;
    int arr[size_arr];
    for (int i = 0; i < size_arr; i++) 
        cin >> arr[i];
    // sort array.
    Quick_Sort(arr, 0, size_arr - 1);
    cout << Solve(arr, size_arr);
    return 0;
}
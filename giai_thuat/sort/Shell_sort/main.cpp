#include <bits/stdc++.h>

using namespace std;

void Shell_Sort(int arr[], int size_arr);
void print(int arr[], int size_arr);

void Shell_Sort(int arr[], int size_arr){
    int temp = size_arr / 2;
    for (int x = temp; x > 0; x /= 2){
        for (int i = 0; i < size_arr; i++){
            for (int j = i; j < size_arr ; j += x){
                if (arr[i] >= arr[j])
                    swap(arr[i], arr[j]);
            }
        }
    }
}
void print(int arr[], int size_arr){
    for (int i = 0; i < size_arr; i++) cout << arr[i] << " ";
}

int main(){
    int size_arr;
    cout << "Input size array: ";
    cin >> size_arr;
    int arr[size_arr];
    cout << endl << "Input array : ";
    for (int i = 0; i < size_arr; i++){
        cin >> arr[i];
    }
    Shell_Sort(arr, size_arr);
    cout << endl << "Output: ";
    print(arr, size_arr);

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

// Hàm thay đổi vị trí hai phân tử trong mảng.
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high)
{
    // Khởi toạ biến pivot lưu giá trị so sánh để phân cách.
    int pivot = arr[high];
    // Khởi tạo biến i lưu chỉ số của phần tử có giá trị lớn hơn, đầu tiên giả sử phần tử đầu có giá trị lớn hơn.
    int i = low;
    // Chúng ta thực hiện chương trình:
    //      Nếu giá trị lớn hơn pivot thì next qua phần tử khác.
    //      Nếu giá trị nhỏ hơn pivot thì "đổi vị trí giá trị đó với trị lớn hơn đang được lưu địa chỉ là i, sau đó giá trị i tăng 1 đơn vị sang giá trị lớn hơn tiếp theo".
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    // Sau khi đoạn code trên thực hiện chúng ta thấy phần tử pivot vẫn ở cuối, chúng ta cần đổi vị trí phần tử pivot vào vị trí vách ngăn.
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
// Hàm in giá trị các phần tử trong mảng
void printArray(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){

    int size_arr;
    cout << "Input size array: ";
    cin >> size_arr;
    int arr[size_arr];
    cout << endl << "Input array: ";
    for (int i = 0; i < size_arr; i++) 
        cin >> arr[i];
    // problem solve 
    Quick_Sort(arr, 0, size_arr - 1);
    cout << endl << "Out put: ";
    printArray(arr, size_arr);

    return 0;
} 

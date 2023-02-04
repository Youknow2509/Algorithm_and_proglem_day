
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b){
    return (a > b) ? a : b;
}

int lis(int *arr,int *arr_tb_res, int n){
    int res = 0;

    for (int i = 0; i < n; i++){
        arr_tb_res[i] = 1;
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (arr[i] > arr[j]){
                arr_tb_res[i] = max(arr_tb_res[i], arr_tb_res[j]+1);
                res = max(res, arr_tb_res[i]);
            }
        }
    }


    return res;
}

void cout_tb_res(int *arr_tb_res, int n){
    for (int i = 0; i < n; i++){
        cout << arr_tb_res[i] << " ";
    }
    cout << endl;
}

void arr_lis(int *arr_tb_res,int *arr, int n, int mx_lenght){
    stack<int> st;
    for (int i = n - 1; i >= 0; i--){
        if (arr_tb_res[i] == mx_lenght){
            st.push(arr[i]);
            mx_lenght--;
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main(){
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    int size_arr;
    cin >> size_arr;
    int arr[size_arr],
        arr_tb_res[size_arr];
    for (int i = 0; i < size_arr; i++){
        cin >> arr[i];
    }
    
    int _lis = lis(arr, arr_tb_res, size_arr);

    cout <<"Length of lis is "<< _lis << endl;
    cout << "Table res: " ; cout_tb_res(arr_tb_res, size_arr);
    cout << "Elements choses: " ; arr_lis(arr_tb_res, arr, size_arr, _lis);
    return 0;
}



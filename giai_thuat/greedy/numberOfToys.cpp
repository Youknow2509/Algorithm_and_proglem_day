
#include <bits/stdc++.h>

using namespace std;

int MAX = 1000;

int numberOfToys(std::vector<int> arr, int k){
    int len = arr.size(),
        i = 0;

    sort(arr.begin(), arr.end());

    while( k >= 0 ){
        k -= arr[i];
        i++;
    }
    return i - 1;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int size_arr,
        k;

    cin >> size_arr;

    vector<int> vt(size_arr);

    for (int i = 0; i < size_arr; i++){
        cin >> vt[i];
    }
    cin >> k;

    cout << "Output: " << numberOfToys(vt, k) << endl; 

    return 0;
}
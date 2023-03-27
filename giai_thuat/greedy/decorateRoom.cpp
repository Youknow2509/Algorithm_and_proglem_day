
#include <bits/stdc++.h>

using namespace std;

long long decorateRoom(int r, int g, int b){

    if ( r == g && g == b)
        return r;

    int arr[3] = {r, g, b}; 
    long long res = 0;
    sort(arr, arr + 3, greater<int>());

    while(arr[0] >= 2 && arr[1] >= 1){
        res++;
        arr[0] -= 2;
        arr[1] --;
        sort(arr, arr + 3, greater<int>());
    }

    while (arr[0] > 0 && arr[1] > 0 && arr[2] > 0) {
        res++;
        arr[0]--;
        arr[1]--;
        arr[2]--;
    }
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int r, g, b;
    cin >> r >> g >> b;

    cout << "Output: " << decorateRoom(r, g, b) << endl;

    return 0;
}
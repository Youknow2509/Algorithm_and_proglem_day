
#include<bits/stdc++.h>

using namespace std;

int MAX = 1000;

int searchElement(std::vector<int> a, int n){
    if (n == 1 ) 
        return a[a.size() - 1];

    int h = 1;

    sort(a.begin(), a.end());
    
    for (int i =a.size() - 1; i >= 0; i--){
        if (a[i] !=a [i+1]){
            h++;
            if (h == n+1)
                return a[i];
        }
    }
    return -1;
}

int main(){

   #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int size_arr, n;
    vector<int> arr(MAX);

    cin >> size_arr;
    
    for (int i = 0; i < size_arr; i++){
        cin >> arr[i];
    }

    cin >> n;

    cout << searchElement(arr, n) << endl;

    return 0;
}


#include <bits/stdc++.h>

using namespace std;

int numberOfSubArray(std::vector<int> arr){
    int n = arr.size(),
        temp_sum = 0,
        res = 0;

    map<int, int> mp;
    map<int, int> :: iterator it;

    for (int i = 0; i < n; i++){
        temp_sum = arr[i];
        mp[temp_sum]++;
        for (int j = i + 1; j < n; j++){
            temp_sum += arr[j];
            mp[temp_sum]++;
        }
    }

    for (it = mp.begin(); it != mp.end(); it++){
        res = (res > it->second) ? res : it->second;
    }
    return res;
}

int main(){

    #ifndef ONLINE_JUDGE 
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int size_vt;

    cin >> size_vt;

    vector<int> vt(size_vt);

    for (int i = 0; i < size_vt; i++){
        cin >> vt[i];
    }

    cout << "Output: " << numberOfSubArray(vt) << endl;

    return 0;
}
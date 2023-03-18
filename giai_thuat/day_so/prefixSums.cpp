
#include <bits/stdc++.h>

using namespace std;

vector<int> prefixSums(vector<int> a){
    int len = a.size();
    vector<int> res(len);
    res[0] = a[0];
    for (int i = 1; i < len; i++){
        res[i] = res[i - 1] + a[i];
    }
    return res;
}

void print_arr(vector<int> vt){
    for (int i = 0; i < vt.size(); i++){
        cout << vt[i] << " ";
    }
    cout << endl;
}

int main(){

    #ifndef ONLINE_JUGDE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int size_vt;
    
    cin >> size_vt;

    vector<int> vt;

    for (int i = 0; i < size_vt; i++){
        int temp_input_vt;
        cin >> temp_input_vt;
        vt.push_back(temp_input_vt);
    }

    vt = prefixSums(vt);

    print_arr(vt);

    return 0;
}
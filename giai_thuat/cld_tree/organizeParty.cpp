
#include <bits/stdc++.h>

using namespace std;

int organizeParty(std::vector<int> P){   
    int size_arr = P.size(),
        res = 0;
    for (int i = 0; i < size_arr; i++){
        int lv_note = 1,
            temp_val = P[i];
        while (temp_val != -1){
            temp_val = P[temp_val - 1];
            lv_note = lv_note + 1;
        }
        res = res >= lv_note ? res : lv_note;
    }
    return res;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int  n;
    cin >> n;

    vector<int> vt(n);

    for (int i = 0; i < n; i++){
        cin >> vt[i];
    }

    cout << organizeParty(vt) << endl;

   return 0;
}
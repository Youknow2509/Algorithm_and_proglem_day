
#include<bits/stdc++.h>

using namespace std;

bool Compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int mettingRoom(std::vector<int> s, std::vector<int> e){

    vector<pair<int, int>> vt;

    for (int i = 0; i < s.size(); i++){
        vt.push_back({ s[i], e[i] });
    }

    sort(vt.begin(), vt.end(), Compare);
    
    int count = 1,
        j = 0;
    for (int i = 1; i < e.size(); i++){
        if (vt[i].first >= vt[j].second){
            count++;
            j = i;
        }
    }

    return count;

}


int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int so_cuoc_hop;
    cin >> so_cuoc_hop;
    vector<int>s(so_cuoc_hop),
        e(so_cuoc_hop);

    for (int i = 0; i < so_cuoc_hop; i++){
        cin >> s[i];
    }
    for (int i = 0; i < so_cuoc_hop; i++){
        cin >> e[i];
    }

    cout << "Output:  "<< mettingRoom(s, e) << endl;

    return 0;
}

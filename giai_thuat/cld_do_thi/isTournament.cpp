
#include <bits/stdc++.h>

using namespace std;

bool isTournament (int n, std::vector<int> fromV, std::vector<int> toV){
    set<int> s[n + 1];

    for (int i = 0; i < n; i++){
        s[fromV[i]].insert(toV[i]);
        s[toV[i]].insert(fromV[i]);
    }

    for (int i = 0; i < n; i ++){
        if (s[i].size() != n - 1)
            return false;
    }
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,
        temp_input;
    vector<int> fromV,
        toV;

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> temp_input;
        fromV.push_back(temp_input);
    }
    for (int i = 0; i < n; i++){
        cin >> temp_input;
        toV.push_back(temp_input);
    }

    if (isTournament(n, fromV, toV)){
        cout << "   True" << endl;
    }else{
        cout << "   False" << endl;
    }

    return 0;
}
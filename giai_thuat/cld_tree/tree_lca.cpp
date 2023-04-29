
#include<bits/stdc++.h>

using namespace std;

std::unordered_map<int, int> parentMap;

std::unordered_map<int, int> build_parent_map(int n, std::vector<std::vector<int> > edges){
    std::unordered_map<int, int> res;
    res[1] = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < edges[i].size(); j++){
            res[edges[i][j]] = i;
        }
    } 
    return res;
}

int lca(int n, std::vector<std::vector<int> > edges, int u, int v){
    parentMap = build_parent_map(n, edges);
    std::set<int> s;
    while(u != 0){
        s.insert(parentMap[u]);
        u = parentMap[u];
    }
    while(v != 0){
        if (s.find(v) != s.end()){
            return v;
        }
        v = parentMap[v];
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
    
    int n, u, v;

    cin >> n;

    vector<vector<int> >edges(n - 1);

    for (int i = 0; i < n - 1; i++){
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
    }

    cin >> u >> v;

    cout << lca(n, edges, u, v);

    return 0;
}

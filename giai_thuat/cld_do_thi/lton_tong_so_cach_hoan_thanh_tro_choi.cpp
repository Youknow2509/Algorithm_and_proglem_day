#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100001; 
vector<int> adj[MAXN]; 
bool visited[MAXN];    

int count_paths = 0;   

void dfs(int v, int n) {
    visited[v] = true;
    if (v == n) {
        count_paths++;
    } else {
        for (int i = 0; i < adj[v].size(); i++){
            if (!visited[adj[v][i]]){
                dfs(adj[v][i], n);
            }
        }
    }
    visited[v] = false;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n, m;
    cin >> n >> m; 
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    
    dfs(1, n);

    cout << count_paths << endl;

    return 0;
}

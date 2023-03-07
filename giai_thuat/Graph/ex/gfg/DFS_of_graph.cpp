
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<int> res;
public:
    void dfs(int node, vector<int> &ans, vector<int> &visited, vector<int> adj[]){
        ans.push_back(node);
        visited[node]=1;

        for (int i = 0; i < adj[node].size(); i++){
            if(visited[adj[node][i]] == 0)
            dfs(adj[node][i], ans, visited, adj);
        }
        
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> visited(V,0);
        vector<int> ans;

        dfs(0, ans, visited, adj);
        return ans;
    }
};

int main() {

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    // V điểm điểm, E cạnh.

    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution obj;
    vector<int> ans = obj.dfsOfGraph(V, adj);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}
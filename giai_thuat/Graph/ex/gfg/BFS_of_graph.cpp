
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]){
        vector<int> res;
        bool ok[V];
        // fill all false
        for (int i = 0; i < V; i++){
            ok[i] = false;
        }
        // solve
        for (int i = 0; i < V; i++){
            if (!ok[i]){
                queue<int> q;
                ok[i] = true;
                q.push(i);

                while(!q.empty()){
                    int temp = q.front();
                    q.pop();
                    res.push_back(temp);
                    for (int j = 0; j < adj[temp].size(); j++){
                        if (!ok[adj[temp][j]]){
                            ok[adj[temp][j]] = true;
                            q.push(adj[temp][j]);
                        }
                    }
                }
            }
        }

        return res;
    }
};

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    
    int V, // lưu số điểm
        E;  // lưu số cạnh    
    cin >> V >> E;

    Solution obj;
    vector<int> adj[V];

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = obj.bfsOfGraph(V, adj);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

int MAX = 1001;
int res = 0;
std::vector<int> adj[MAX];
std::vector<bool> visited[MAX];

void dfs (int u, int len, vector<int>&vt){
	visited[u] = true;
	vt.push_back(len);
	for (int i = 0; i < adj[u].size(); i++){
		if (!visited[adj[u][i]]){
			dfs(adj[u][i], len + 1, vt);
		}
	}
}

int kPath(int n, std::vector<std::vector<int>> edges, int k){
	int len = edges.size();
	for (int i = 0; i < len; i++){
		adj[edges[i][0]].push_back(edges[i][1]);
		adj[edges[i][1]].push_back(edges[i][0]);
	}

	for (int i = 1; i <= n; i++){
		vector<int> vt;
		memset(visited, false, MAX);
		dfs(i, 0, vt);
		int size_vt = vt.size();
		for (int j = 0; j < size_vt; j++){
			if (vt[i] == k){
				res ++;
			}
		}
	}

	return res;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
	#endif

	int n, k, size_edges;

	cin >> n;

	vector<vector<int> > edges(size_edges);

	for (int i = 0; i < size_edges; i++){
		int u, v;
		cin >> u >> v;
		edges[u].push_back(v);
	}

	cin >> k;

	cout << kPath(n, edges, k) << endl;

	return 0;
}
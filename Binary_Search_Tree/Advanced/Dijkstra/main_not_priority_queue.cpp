
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int m, n;

int tim_va_danh_dau_diem_co_khoang_cach_ngan_nhat(vector<int> distant, vector<bool> visited){
    int Min = INF, res;
    for (int i = 0; i < n; i++){
        if (!visited[i] && distant[i] < Min){
            Min = distant[i]; res = i;
        }
    }
    return res;
}

void dijkstra(int s, vector<vector<int> >graph, vector<int>& distant, vector<bool>& visited){
    int temp;
    distant[s] = 0;
    for (int i = 0; i < n; i++){
        temp = tim_va_danh_dau_diem_co_khoang_cach_ngan_nhat(distant, visited);
        visited[temp] = true;
        // cập nhập khoảng cách
        for (int j = 0; j < n; j++){
            if (!visited[j] && graph[temp][j] + distant[temp] < distant[j]){
                distant[j] = graph[temp][j] + distant[temp];
            }
        }
    }
}

void in_kq(int s, vector<int> distant){
    for (int i = 0; i < n; i++){
        if (s != i){
            cout << s << " -> " << i << ": " << distant[i] << endl;
        }
    }
    cout << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif

    int s,
        u, v, kc;

    cin >> n >> m >> s;

    vector<vector<int> > graph(n, vector<int>(n, INF));
    vector<int> distant(n, INF);
    vector<bool> visited(n, INF);

    for (int i = 0; i < m; i++){
        cin >> u >> v >> kc;
        graph[u][v] = kc;
    }

    dijkstra(s, graph, distant, visited);

    in_kq(s, distant);

    return 0;
}
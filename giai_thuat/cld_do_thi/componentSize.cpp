
#include <bits/stdc++.h>

using namespace std;

queue <int> q;
bool check[1000];
int dem = 1;
void BFS(std::vector<std::vector<bool>> matrix, int st)
{
    q.push(st);
    check[st] = true;
    
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < matrix.size(); i++)
            if(check[i] != true && matrix[u][i] == true)
                {
                    q.push(i);
                    check[i] = true;
                    dem++;
                }
        
    }
}

int componentSize(std::vector<std::vector<bool>> matrix, int vertex)
{
    BFS(matrix, vertex);
    return dem;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);



    return 0;
}
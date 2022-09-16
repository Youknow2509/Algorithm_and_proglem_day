//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

public:
    vector<int> a;

    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        int result = 0;
        // sắp xếp lại mảng hai chiều  
        sort(m,roads);
        // Tìm 0 để bắt đầu 
        for (int i = 0; i < m; i++){
            if (roads[i][0] == 0){
                // bắt đầu vào hàm ....
                result += solve(n,m, roads, roads[i][1],roads[i][2]);
            }
        }
        
        return count();
    }

    void sort(int m, vector<vector<int>>& roads){
        for (int i = 0; i < m; i++){
            if (roads[i][0] > roads[i][1] ){
                int j = roads[i][0];
                roads[i][0] = roads[i][1];
                roads[i][1] = j;
            }
        }
    }

    int solve(int n,int m, vector<vector<int>> roads, int next_loc, int time){
        int case_t = 0;

        if (next_loc == (n-1)){
            a.push_back(time);
            case_t ++;
            return 0;
        }

        for (int i = 0; i < m; i++){
            if (roads[i][0] == next_loc){
                time += roads[i][2];
                 case_t += solve(n,m, roads, roads[i][1],time);
            }
        }
        
        return case_t;
    }
    
    int count(){
        int time_min = a[0];
        int count = 1;
        for (int i = 1; i < a.size(); i++){
            if (a[i] == time_min) count ++;
            if (time_min > a[i]){
                count = 0;
                time_min = a[i];
            }
        }
        return count;
    }

    void prt_time(){
        for (int i = 0; i < a.size();i++){
            cout << a[i] << " ";
        }
    }
};

int main(){
    int n,m;
    n=7; m=10;
    vector<vector<int>> adj;
    adj = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};

    Solution obj;
    cout << obj.countPaths(n, adj) << "\n";
    
    obj.prt_time();
    return 0;
}

/* int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
} */



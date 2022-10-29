
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    void solve(int i, int n, string contact[], string s){
        
    }
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // n la so gia tri nhap vao contact
        // s la gia tri so sanh
        vector<vector<string>> result;

        for (int i = 0; i < s.length(); i ++){
            solve(i, n, contact, s);
        }

        return result;
    }
};


int main(){
    
    int n;
    cin>>n;
    string contact[n], s;

    for(int i = 0;i < n;i++)
        cin >> contact[i];

    cin >> s;
    
    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for(int i = 0;i < s.size();i++){
        for(auto u: ans[i])
            cout<<u<<" ";
        cout<<"\n";
    }
    
    return 0;
}

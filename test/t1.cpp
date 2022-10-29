
#include <bits/stdc++.h>
using namespace std;

class Solution{
private: 
    void solve(int i, string contact[], string s, vector<vector<string>>& result, int j){
        if (s[i] == contact[0][i]) {
            result[i].push_back(contact[0]);
        }
        else j ++;

        if (s[i] == contact[1][i]) {
            result[i].push_back(contact[1]);
        }
        else j ++;

        if (s[i] == contact[2][i]) {
            result[i].push_back(contact[2]);
        }
        else j ++;

        if ( j == 3) result[i].push_back("0");


    }
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // n la so gia tri nhap vao contact
        // s la gia tri so sanh
        vector<vector<string>> result;

        for (int i = 0; i < s.length(); i ++){
            solve(i, contact, s, result, 0);
        }

        return result;
    }
};


int main(){
    
    int n = 3;
    string contact[3] = {"geeikistest", "geeksforgeeks","geeksfortest"} , s = "geeips";

    
    
    Solution ob;
    vector<vector<string>> ans = ob.displayContacts(n, contact, s);
    for(int i = 0;i < s.size();i++){
        for(auto u: ans[i])
            cout<<u<<" ";
        cout<<"\n";
    }
    
    return 0;
}
/* int main(){
    
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
 */
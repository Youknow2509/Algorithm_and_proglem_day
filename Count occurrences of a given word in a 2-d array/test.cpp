//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public: 
    int findOccurrence(vector<vector<char>>&m, string t){
        int r=m.size(),c=m[0].size(),ans=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(m[i][j]==t[0])
                    ans+=solve(m,t,i,j,t.size(),0,r,c);
            }
        }
        return ans;
    }
    
int solve(vector<vector<char>>&m,string t,int i,int j,int size,int idx,int r,int c)
    {
        int f=0;
        if(i>=0 && j>=0 && i<r && j<c && t[idx]==m[i][j])
        {
            char temp=m[i][j];
            idx++;
            m[i][j]=0;
            if(idx==size)
                f=1;
            else
            {
                f+=solve(m,t,i+1,j,size,idx,r,c);
                f+=solve(m,t,i,j+1,size,idx,r,c);
                f+=solve(m,t,i-1,j,size,idx,r,c);
                f+=solve(m,t,i,j-1,size,idx,r,c);
            }
            m[i][j]=temp;
        }
        return f;
    }
};
//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends

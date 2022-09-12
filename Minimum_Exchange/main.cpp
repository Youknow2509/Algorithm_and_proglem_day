//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
int MinimumExchange(vector<vector<char>>matrix){
    int case_1 = 0;
    int case_2 = 0;
    
    for(int i = 0; i < matrix.size(); i++){
        for (int j = 0; j <matrix[0].size(); j++){
            if ((i+j)%2==0){
                if(matrix[i][j] != 'A') case_1 ++;
                else case_2 ++;
            }
            else {
                if(matrix[i][j] == 'A') case_1 ++;
                else case_2 ++;
                }
            
        }
    }
    return min(case_1,case_2);
}

};

//{ Driver Code Starts.
//main debug 
int main(){
	
		int n, m;
		n = 3;
        m = 4;
		vector<vector<char> >matrix(n);
		matrix = {{'A','A','B','A'},{'B','A','B','A'},{'B','B','A','B'}};
		Solution obj;
		int ans = obj.MinimumExchange(matrix);
        cout << ans;
	    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        int temp[100000]={0};
        int maxIndex=0;
        for(int i=0;i<N;i++){
            temp[arr[i]]=1;
            maxIndex=max(maxIndex, arr[i]);}
        for ( int i : temp) cout << i <<" ";
        cout << endl;
        int maxCount=0; int count=0;
        for(int i=1;i<=maxIndex;i++){
            if(temp[i])
                count++;
            else
                count=0;
            maxCount=max(maxCount, count);}
        return maxCount;
    }
};
//{ Driver Code Starts.
 
// Driver program
int main(){

    int  n = 20;

    int a[n] = {6,6,2,3,1,4,1,5,6,2,8,7,4,2,1,3,4,5,9,6};

    Solution obj;
    cout<<obj.findLongestConseqSubseq(a, n);     
    }
// } Driver Code Ends
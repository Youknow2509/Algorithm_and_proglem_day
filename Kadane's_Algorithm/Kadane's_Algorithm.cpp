#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
       int sum , max_sum ;
       sum = max_sum = arr[0];

       for (int i = 1; i < n; i ++){
        sum += arr[i];
        if ( arr[i] > sum) sum = arr[i];        
        if (sum > max_sum) max_sum = sum;
       }

        return max_sum;


    }
};

int main()
{
    int n ;
    n = 9;
    int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
    Solution ob;
    cout << "MaxSubarraySum: " <<ob.maxSubarraySum(a, n) << endl;

    /* int t,n;
    cout << "Nhap so lan chuong trinh chay: " ;cin>>t; 
    cout << endl;

    while(t--) 
    {
        cout << "Nhap so phan tu cua mang: " ;cin>>n; 
        cout << endl;

        int a[n];
        
        for(int i=0;i<n;i++){
            cout << "a[" << i <<"] = ";
            cin>>a[i]; 
            cout << endl;
        }    
        Solution ob;
        cout << "MaxSubarraySum: " <<ob.maxSubarraySum(a, n) << endl;
    } */


}


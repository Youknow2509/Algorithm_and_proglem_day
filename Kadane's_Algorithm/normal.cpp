#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        
        int sum, max_sum ;
        max_sum = arr[0];
        
        for(int i = 0; i < n; i ++){
          sum = arr[i];
          if ( sum > max_sum) max_sum = sum;

          for(int j = i + 1; j < n; j ++){
            sum += arr[j];
            if ( sum > max_sum) max_sum = sum;
          }
          

        } 
        return max_sum;
        //Cách làm này bình thường tính từng mảng con liên tiếp và so sánh giá trị cái nào lớn nhất

    }
};

int main()
{
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

    int n ;
    n = 2;
    int a[2] = {-99, 10};
    Solution ob;
    cout << "MaxSubarraySum: " <<ob.maxSubarraySum(a, n) << endl;

}


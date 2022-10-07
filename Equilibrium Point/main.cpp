//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
private:
    long long Sum_arr(long long a[],int n){
        long long s = 0;
        for (int i = 0; i < n; i++ ) s += a[i];
        return s;
    }
public:
    int equilibriumPoint(long long a[], int n) {
    
        if (n == 1 ) return 1;
        long long sum = 0;
        
        sum = Sum_arr(a,n);

        long long sum_1 =0, sum_2 = 0;
        
        for (int i = 1; i < n; i++){
            sum_1 +=a[i-1];
            sum_2 = sum - ( sum_1 + a[i] );
            if (sum_1 == sum_2) return i + 1;
        }

        return -1;
    }

};



//{ Driver Code Starts.


int main() {

    
    long long n;
    cout << "Nhap so phan tu cua mang: " ; cin >> n; cout << endl;
    long long a[n];
    for(int i = 0; i < n; i ++){
        cout << "A[" << i <<"] = " ;
        cin >> a[i];
        cout << endl;
    }
    
    Solution ob;
    cout <<"Solve = ";
    //calling equilibriumPoint() function
    cout << ob.equilibriumPoint(a, n) << endl;
    
    return 0;
}

// } Driver Code Ends
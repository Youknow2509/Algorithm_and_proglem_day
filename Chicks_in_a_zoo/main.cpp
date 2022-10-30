#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int NoOfChicks(int n){
        //code here
        vector<long long> ck_day;
        ck_day.push_back(1);
        long long ck = 1;
        int j = 0;
        for(int i = 0; i < n-1 ; i++){
            if ( i >=5 ){
                ck -=ck_day[j];
                j++;
            }

            ck_day.push_back(ck*2);
            ck += ck*2;
            
        }
        return ck;
	} 
};

int main(){
    int N;

    cout << "Input N = ";
    cin >> N;
    cout << endl;

    Solution obj;
    long long int ans = obj.NoOfChicks(N);
    cout <<"Output: "<<  ans << endl;
	
	return 0;
}
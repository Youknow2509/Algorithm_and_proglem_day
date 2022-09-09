#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
	string digitsNum(int N)
	{   string result="";
        int M = N;
        while (N > 9){
            result += '9';
            N -= 9;
        }
    // Chen so nho hon 9 len dau
    result = to_string(N) + result;
    for (int i = 0; i < M; i++){result +='0';}
    return result;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		string ans = ob.digitsNum(n);
		cout << ans <<"\n";
	}
	return 0;
}


#include <bits/stdc++.h>

using namespace std;

long long solve(int n){
	if (n == 1 || n == 2) return 1;
	return solve(n-1) + solve(n-2);
}

int main(){
    int a;
    cin >> a;
    cout << solve(a);   
    return 0;
}
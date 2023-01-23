#include<iostream>

using namespace std;
int count = 0;
void convert(int n, int k){
	if (k == 0){
		count ++;
	}
	else{
		convert(2*n, k-1);
		if ((n-1)%3 == 0 && ((n-1)/3)%2 != 0){
			convert((n-1)/3, k-1);
		}
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	convert(n, k);
	cout << count;
	return 0;
}
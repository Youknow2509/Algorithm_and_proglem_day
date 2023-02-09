#include<iostream>

using namespace std;

int s[10001][2];
int a[10001];
int chooseGifts(int a[], int n)
{
    for (int i = 0; i < n; i++){
		s[i][0] = a[i];
		s[i][1] = 0;
	}
	for (int i = 1; i < n; i++){

		for (int j = 0; j < i; j++)
		    if (a[j] == a[i] && s[j][0] + a[i] > s[i][1])
		        s[i][1] = s[j][0] + a[i];

		for (int j = 0; j < i; j++)
		    if (s[j][1] + a[i] > s[i][0])
		        s[i][0] = s[j][1] + a[i];
	}
	int max = -1;
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < 2; j++)
	        if (s[i][j] > max) max = s[i][j];
    return max;
}

void in_s(int n){
    for (int i = 0; i < n; i++){
        cout << a[i] << "		" << s[i][0] << "   " << s[i][1] << endl;
    }
}

int main(){
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << chooseGifts(a, n) << endl;
    in_s(n);
	return 0;
}
#include<iostream>

using namespace std;

int l[1001][1001];
string longestChainSymmetry(string s)
{
    string x = s;
    string y = "";
    for (int i = s.length() - 1; i >= 0; i --) 
        y = y + x[i];
    int m = x.length(), n = y.length();
    x = ' ' + x;
    y = ' ' + y;
    // cout << x << endl << y << endl;

	for (int i = 0; i <= m; i++) l[i][0] = 0;
	for (int j = 0; j <= n; j++) l[0][j] = 0;
        
    for (int i = 1; i <= m; i++) {
	    for (int j = 1; j <= n; j++) {
            if (x[i] == y[j]) l[i][j] = l[i-1][j-1] + 1;
            else l[i][j] = max(l[i-1][j], l[i][j-1]);
        }
    } 
    string p = "";
    while (l[m][n] > 0 && m > 0 && n > 0){
    	while (l[m-1][n] == l[m][n]) m --;	 
		while (l[m][n] == l[m][n-1]) n --;	
		p = x[m] + p;
		m --;
		n --; 	
	}
   return p;
}
int main(){
    freopen("INP.TXT", "r", stdin);
    freopen("OUT.TXT", "w", stdout);
    string s;
    getline(cin, s);
    cout << longestChainSymmetry(s) << endl;
    for (int i  = 0; i < s.length(); i++){
        for (int j = 0; j < s.length(); j++){
            cout << l[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
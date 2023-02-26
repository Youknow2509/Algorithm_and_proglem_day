/* 
Cho biết số trang sách của 1 quyển sách

Hãy tìm số lượng các chữ số dùng để đánh số trang của quyển sách đó
*/
#include<bits/stdc++.h>

using namespace std;

int _scs(int n){
    int res = 0;
    while (n > 0){
        n /= 10;
        res++;
    }
    return res;
}

int pow(int a, int b){
    if (!b) return 1;
    int res = 1;
    
    while(b--){
        res *= a;
    }
    return res;
}

int pagesNumbering(int n){
    int scs = _scs(n),
        res = 0;
    for (int i = 1; i < scs; i++){
        res += (pow(10,i) - pow(10,i - 1))*i;
    }
    return res + scs*(n - pow(10,scs-1) +1);
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;
    cin >> n;
    cout << pagesNumbering(n) << endl;

    return 0;
}

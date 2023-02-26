/* 
Cho số nguyên n, hãy tính tổng các số nguyên tố nhỏ hơn hoặc bằng n
Bởi vì tổng các số nguyên tố nhỏ hơn hoặc bằng n có thể rất lớn, nên hãy trả ra kết quả 
của tổng trên dưới dạng là số dư trong phép chia của tổng trên cho 22082018.
*/
// => sang nguyen to ....
#include<bits/stdc++.h>

using namespace std;


bool a[10000001];
void snt(int n){
    for (int i = 2; i <= n; i++){
        a[i]=1;
    }
    a[0] = a[1] = 0;
    for (int i = 2; i <= sqrt(n); i++){
        if (a[i]){
            for (int j = 2 * i; j <= n; j += i){
                a[j] = 0;
            }
        }
    }
}
int primeSum(int n)
{
    int mod = 22082018;
    snt(n);
    int d = 0;
    for (int i = 2; i <= n; i++){
        if (a[i]) {
            d = (d + i % mod) % mod;
        }
    }
    return d;
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
    cout << primeSum(n)  << endl;

    return 0;
}

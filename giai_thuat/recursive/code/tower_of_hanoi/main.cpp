

#include<bits/stdc++.h>

using namespace std;

void tower_of_hanoi(int n, char from, char to, char temp){
    if (n <= 0){
        return;
    }
    tower_of_hanoi(n - 1, from, temp, to); // move n - 1 disk: A to B.
    cout << "Move disk " << n << " from " << from << " to " << to << endl; // move disk A to C.
    tower_of_hanoi(n - 1, temp, to, from); // move n - 1 disk B to C.
}

void v1(int n, char A, char C, char B);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n;

    cin >> n;

    tower_of_hanoi(n, 'A', 'C', 'B');

    return 0;
}



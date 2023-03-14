
#include<bits/stdc++.h>

using namespace std;

bool bishopAndPawn(string bishop, string pawn){
    return (abs(bishop[0] - pawn[0]) == abs(bishop[1] - pawn[1]) && bishop[0] - pawn[0] != 0);
}

int main(){

   #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string bishop, pawn;

    cin >> bishop >> pawn;

    if (bishopAndPawn(bishop, pawn)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

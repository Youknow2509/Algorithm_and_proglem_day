
#include<bits/stdc++.h>

using namespace std;



int chessKnight(string Cell){
    int row[8] = {2, 1, -1, -2, -2, -1, 1, 2},// chenh lech ve hang
        col[8] = {1, 2, 2, 1, -1, -2, -2, -1};// chenh lech ve cot

    int x = Cell[0] - 'a' + 1, // ki tu luu hang la cac chu cai tu 'a' -> 'h' => bien doi dang so tu 1 den 8
        y = Cell[1] - '0';

    int res = 0;

    for (int i = 0; i < 8; i++){
        int _x = x + row[i],
            _y = y + col[i];
        if ( _x > 0 && _y > 0 && _x <= 8 && _y <= 8){
            res++;
        }
    }
    return res;
}

int main(){

   #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string Cell;

    cin >> Cell;
    if (chessKnight(Cell)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

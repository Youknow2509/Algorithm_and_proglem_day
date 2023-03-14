
#include<bits/stdc++.h>

using namespace std;

/*
    Trong bàn cờ một ô cùng có chỉ số cùng tính chẵn lẻ là ô màu đen, và ngược lại.
    Kích thước ô bàn cờ 8*8.
*/
/* 
int checkColor(string cell) {
	int x = cell[0] - 'A' + 1, y = cell[1] - '0';
	// viet lai form cua toa do (1 .. 8, 1 .. 8)
	return x % 2 == y % 2 ? 1 : 0;
	// 1 la black, 0 la white
}
 */
bool chessBoardCellColor(string cell1, string cell2){
    if((cell1[0] + cell1[1] + cell2[0] + cell2[1]) % 2 == 0)
        return true;
    return false;
}

int main(){

   #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string cell1, cell2;

    cin >> cell1 >> cell2;

    if (chessBoardCellColor(cell1, cell2)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

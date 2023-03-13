
#include<bits/stdc++.h>

using namespace std;

/* 
 a -> z: 97 -> 122
 A -> Z: 65 -> 90
 0 -> 9: 48 -> 57

 !  -> 33

 #  -> 35
 $  -> 36
 %  -> 37
 &  -> 38

 (  -> 40
 )  -> 41
 *  -> 42
 +  -> 43

 -  -> 45

 @  -> 64
 
 ^  -> 94
 */

bool checkStrongPassword(string password){
    int n = password.length();
    if ( n < 6 ) return false;
    bool t1, t2, t3, t4;
    for (int i = 0; i < n; i++){
        if (int(password[i]) <= 122 && int(password[i]) >= 97){
            t2 = true;
            continue;
        }
        if (int(password[i]) <= 90 && int(password[i]) >= 65){
            t3 = true;
            continue;
        }
        if (int(password[i]) <= 57 && int(password[i]) >= 48){
            t1 = true;
            continue;
        }
        if ((int(password[i]) == 33)||(int(password[i]) == 45)||(int(password[i]) == 64)||(int(password[i]) == 94)||(int(password[i]) >= 35 && int(password[i]) <= 38)||(int(password[i]) >= 40 && int(password[i]) <=43)){
            t4 = true;
        }
    }
    return t1 && t2 && t3 && t4;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    string str;

    getline(cin, str);

    cout << "Check strong passsword: " << checkStrongPassword(str) << endl;

    return 0;
}

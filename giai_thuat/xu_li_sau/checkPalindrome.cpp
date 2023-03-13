
#include<bits/stdc++.h>

using namespace std;

bool checkPalindrome(std::string inputString)
{
    string s = "";
    for (int i = inputString.length() - 1; i >= 0; i--)
        s = s + inputString[i];
    return s == inputString;
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

    if(checkPalindrome(str)){
        cout << str << " true" << endl;
    }
    else{
        cout << str << " false" << endl;
    }

    return 0;
}

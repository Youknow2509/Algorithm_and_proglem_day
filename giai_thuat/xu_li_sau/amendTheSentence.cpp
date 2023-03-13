
#include <bits/stdc++.h>

using namespace std;

string amendTheSentence(string s){
    string result;
    if (s[0] >= 'A' && s[0] <= 'Z')
        s[0] += 32;
    for (int i = 0; i <s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            result = result + " " + char(s[i] + 32);
        else
            result = result + s[i];
    return result;
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

    cout << "Amend the sentence: " << amendTheSentence(str) << endl;

    return 0;
}

#include<bits/stdc++.h>

using namespace std;

bool charactersRearrangement(string string1, string string2){
    int len1 = string1.length(),
        len2 = string2.length();
    vector<int> A(256, 0),
        B(256, 0);   

    if (len1 != len2) 
        return false;
    for (int i = 0; i < len1; i++){
        A[string1[i]]++;
    }
    for (int i = 0; i < len2; i++){
        B[string2[i]]++;
    }
    if (A == B)
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
    
    string str1,
        str2;

    cin >> str1 >> str2;

    if (charactersRearrangement(str1, str2)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}

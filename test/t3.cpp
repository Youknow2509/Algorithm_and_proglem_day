
#include<bits/stdc++.h>

using namespace std;

string encodeString(string s)
{
    s = s + '@';
    stack<char> st;
    string str = "";
    for (int i = 0; i < s.length(); i++){
        if (st.empty() || st.top() == s[i]){
            st.push(s[i]);
        } else {
            int count = 0;
            str = str + st.top();
            while(!st.empty()){
                count++;
                st.pop();
            }
            str = str + to_string(count);
            st.push(s[i]);
            count = 1;
        }
    }
    return str;
}

int main(){
    
    string a = encodeString("aaabbaaac");
    cout << a;
    return 0;
}
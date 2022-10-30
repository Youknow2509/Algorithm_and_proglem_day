
#include<bits/stdc++.h>

using namespace std;

void repeat(stack <char> &ms, string str, int num)
{
    for (int i = 0; i < num; i++)
    // use c++ 11    for (auto x : str)
    //push each becase var ms  "char" and var str "string";
        for(int i = 0; i < str.length(); i++)
        	ms.push(str[i]); 
}

string decodeString(string s)
{
    stack <char> ms;
    // use c++ 11    for (auto x : str)    
    //for (auto x : s)
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ']')
        {
            string chr;
            string ans = "";
            int num = 0, base = 1;
            while (ms.top() != '[')
            {
                chr = ms.top();
                ms.pop();
                ans = chr + ans; 
                
            }
            ms.pop(); // delete "["
            // solve number 
            while (!ms.empty() && '0' <= ms.top() && ms.top() <= '9')
            {
                num += (ms.top() - '0')*base;
                base *= 10;
                ms.pop();
            }
            repeat(ms, ans, num);
        }
        else
            ms.push(s[i]);
    }
    string res = "";
    while(!ms.empty())
	{
		char x = ms.top();
    	res.push_back(x);
    	ms.pop();
	}
	reverse(res.begin(), res.end());
    return res;
}

int main(){

    string a = "3[a]", b = "3[b2[ca]]";

    cout << a <<" -> " << decodeString(a) << endl;
    cout << b <<" -> " << decodeString(b) << endl;



    return 0;
}
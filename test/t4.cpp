
#include<bits/stdc++.h>

using namespace std;

void repeat(stack <char> &ms, string str, int num)
{
    string res = "";
    for (int i = 0; i < num; i++)
        for (auto x : str)
        	ms.push(x);
}

string decodeString(string s)
{
    stack <char> ms;
    for (auto x : s)
    {
        if (x == ']')
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
            ms.pop();
            while (!ms.empty() && '0' <= ms.top() && ms.top() <= '9')
            {
                num += (ms.top() - '0')*base;
                base *= 10;
                ms.pop();
            }
            repeat(ms, ans, num);
        }
        else
            ms.push(x);
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

    string a = "3[a]";
    
    //string b = "3[b2[ca]]";

    cout << a <<" -> " << decodeString(a) << endl;
   // cout << b <<" -> " << decodeString(b) << endl;



    return 0;
}

#include <bits/stdc++.h>

using namespace std;

vector<string> generateBinary(int n)
{
    vector<string> res;
	queue<string>q;
	q.push("1");
	while(n--){
        q.push(q.front() + "0");
		q.push(q.front() + "1");
		res.push_back(q.front());		
		q.pop();
	}
    return res;
}

int main(){

    int n;
    vector<string> rs;

    cout << "Input: n = ";
    cin >> n;
    cout << "Output: " << endl;

    rs = generateBinary(n);

    for(int i = 0; i < rs.size(); i++) cout << rs[i] << ", ";
    cout << endl;
    return 0;
}
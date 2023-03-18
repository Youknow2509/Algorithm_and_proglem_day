
#include<bits/stdc++.h>

using namespace std;

bool isMonotonous(vector<int> sequence){
    int len = sequence.size();
    if (len == 1) 
        return true;
    if (len == 2)
        return (sequence[0] == sequence[1]) ? false : true;
    for (int i = 2; i < len; i++){
        if ((sequence[1] - sequence[0])*(sequence[i] - sequence[1]) <= 0)
            return false;
    }
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
	freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    vector<int> sequence;
    int size_sequence;

    cin >> size_sequence;

    for (int i = 0; i < size_sequence; i++){
        int temp_input_arr;
        cin >> temp_input_arr;
        sequence.push_back(temp_input_arr);
    }

    if(isMonotonous(sequence)){
        cout << "   True" << endl;
    }
    else{
        cout << "   False" << endl;
    }

    return 0;
}

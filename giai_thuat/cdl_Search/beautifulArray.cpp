
#include <bits/stdc++.h>

using namespace std;

int MAX = 10000;

bool beautifulArray(std::vector<int> arr){
    int size_arr = arr.size();
    vector<int> mcd(size_arr);
    mcd[0] = arr[0];
    for (int i = 1; i <size_arr; i++){
        mcd[i] = mcd[i-1] + arr[i];
    }

    for (int i = 1; i < size_arr - 1; i++){
        if (mcd[i-1] == mcd[size_arr-1] - mcd[i])
            return true;
    }

    return false;
}

int main(){

    int size_arr;
    vector<int> vt(MAX);

    cin >> size_arr;

    for (int i = 0; i < size_arr; i++){
        cin >> vt[i];
    }

    if (beautifulArray(vt)){
        cout << "   True" << endl;
    }
    else{
        cout << "   False" << endl;
    }

    return 0;
}
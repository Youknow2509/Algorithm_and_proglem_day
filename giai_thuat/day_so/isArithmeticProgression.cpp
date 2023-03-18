
#include <bits/stdc++.h>

using namespace std;

bool isArithmeticProgression(std::vector<int> sequence)
{
    if (sequence.size() == 1)
        return true;
    int k = sequence[1] - sequence[0];
    for (int i = 1; i < sequence.size(); i++)
        if (sequence[i]-sequence[i-1]!=k) 
            return false;
    return true;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("Show_screen/INP.TXT", "r", stdin);
    freopen("Show_screen/OUT.TXT", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //

    //

    return 0;
}
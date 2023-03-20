#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
    int n;
    cin >> n;

    ll coins[n];

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + n); 

    ll min_value = 1; 
    
    for (int i = 0; i < n; i++) {
        if (coins[i] > min_value) {
            break;
        }
        min_value += coins[i];
    }

    cout << min_value << endl;

    return 0;
}

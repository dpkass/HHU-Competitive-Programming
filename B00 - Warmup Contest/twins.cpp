#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    int half_coin_val = accumulate(coins, coins + n, 0) / 2;

    sort(coins, coins + n, greater<int>());

    for (int i = 1; i < n; ++i) {
        if (accumulate(coins, coins + i, 0) > half_coin_val) {
            cout << i << endl;
            return 0;
        }
    }
}
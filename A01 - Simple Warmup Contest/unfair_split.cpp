//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl

void solve() {
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; ++i) cin >> coins[i];

    sort(coins, coins + n, greater<int>());

    int half_coin_val = accumulate(coins, coins + n, 0) / 2;
    int sum = 0, i = 0;
    while (sum <= half_coin_val) sum += coins[i++];

    print(i);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
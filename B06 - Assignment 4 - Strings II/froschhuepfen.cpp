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
#define ll long long

void solve() {
    int x, k;
    cin >> x >> k;

    if (x % k) {
        print(1);
        print(x);
    } else {
        print(2);
        print(x + 1 << ' ' << -1);
    }
}

int main() {
    Speed;

    int t;
    cin >> t;

    while (t--)
        solve();


    return 0;
}
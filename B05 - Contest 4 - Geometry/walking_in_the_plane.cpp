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
    ll x1, y1, x2, y2;
    cin >> x1 >>y1 >> x2 >> y2;

    x2 -= x1;
    y2 -= y1;

    if(y2 < 0 || y2 < x2) print(-1);
    else print(y2 * 2 - x2);
}

int main() {
    Speed;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
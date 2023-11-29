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
#define print_col(a) for(auto item: a) cout << item << ' '

//#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef set<int> si;

void solve() {
    int n, x;
    cin >> n >> x;

    vi stations(n + 2);
    stations[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> stations[i];
    stations[n + 1] = stations[n] + 2 * (x - stations[n]);

    int maxd = INT16_MIN;
    for (int i = 0; i <= n; ++i)
        maxd = max(maxd, stations[i + 1] - stations[i]);

    print(maxd);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
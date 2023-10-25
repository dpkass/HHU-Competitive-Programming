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
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

ll single_best(ll c1, ll c2, ll c3, vi &busses) {
    ll sum = 0;
    for (int i: busses)
        sum += min(i * c1, c2);
    return min(sum, c3);
}

void solve() {
    ll c1, c2, c3, c4;
    ll n, m;
    cin >> c1 >> c2 >> c3 >> c4 >> n >> m;

    vi busses, subways;
    for (int i = 0, x; i < n; ++i) cin >> x, busses.push_back(x);
    for (int i = 0, x; i < m; ++i) cin >> x, subways.push_back(x);

    ll bus_best = single_best(c1, c2, c3, busses);
    ll subway_best = single_best(c1, c2, c3, subways);

    print(min(bus_best + subway_best, c4));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
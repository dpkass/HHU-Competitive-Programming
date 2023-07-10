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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;
typedef multiset<int> msi;
typedef multiset<pi> msii;

//#define int ll

void solve() {
    ll n, d, h;
    cin >> n >> d >> h;
    ld sum = n * d * h / 2.0;

    ld yp, y;
    cin >> yp;
    for (ll i = 1; i < n; yp = y, ++i) {
        cin >> y;
        if (yp + h <= y) continue;

        ld height = yp + h - y, base = d * height / h;
        sum -= height * base / 2;
    }

    print(setprecision(16) << sum);
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
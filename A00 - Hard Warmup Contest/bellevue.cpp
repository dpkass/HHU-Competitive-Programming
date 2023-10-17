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

#define max(x, y, z) max(max(x,y),z)

//#define int ld

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;
typedef multiset<int> msi;
typedef multiset<pi> msii;

ld calc_m(const pi &c, const pi &l) {
    return abs((c.second - l.second) / (c.first - l.first));
}

void solve() {
    int n;
    cin >> n;

    vii coord;
    coord.reserve(n);
    for (int i = 0, x, y; i < n; ++i) cin >> x >> y, coord.emplace_back(x, y);

    pi l = coord[0], r = coord[n - 1];
    ld m = 0;
    for (int i = 1; i < n - 1; ++i) {
        pi c = coord[i];
        ld temp_m_l = calc_m(c, l);
        ld temp_m_r = calc_m(c, r);
        m = max(temp_m_l, temp_m_r, m);
    }

    cout.precision(20);
    print(atan(m) * (180.0 / M_PI));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}

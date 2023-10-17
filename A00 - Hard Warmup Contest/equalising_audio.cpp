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

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;
typedef multiset<int> msi;
typedef multiset<pi> msii;

void solve() {
    ll n, x;
    cin >> n >> x;

    vld vals;
    vals.reserve(n);

    for (ll i = 0, j; i < n; ++i) cin >> j, vals.push_back(j);

    ld sq_sum = accumulate(vals.begin(), vals.end(), 0l, [](ll acc, ll x) { return acc + x * x; });

    if (sq_sum != 0) {
        ld norm = sqrt(x * n / sq_sum);
        for (auto &val: vals) val *= norm;
    }

    cout.precision(20);
    print_col(vals);
}

signed main() {
    Speed;

    solve();

    return 0;
}

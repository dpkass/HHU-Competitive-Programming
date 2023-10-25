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
typedef pair<ll, ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vii;
typedef set<ll> si;
typedef set<pi> sii;

void solve() {
    ll n;
    cin >> n;

    vi a;
    for (ll i = 0, x; i < n; ++i)
        cin >> x, a.push_back(x);

    ll sum = accumulate(a.begin(), a.end(), 0ll);
    sort(a.begin(), a.end());

    ll res = sum;
    for (ll i = 0; i < n - 1; ++i) {
        res += sum;
        sum -= a[i];
    }

    print(res);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
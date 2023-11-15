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

ll powmod(ll base, ll pow, ll mod) {
    base %= mod;
    ll res = 1;
    while (pow > 0) {
        if (pow % 2) res = (res * base) % mod;
        base = (base * base) % mod;
        pow /= 2;
    }
    return res;
}

void solve() {
    ll n, k, m;
    cin >> n >> k >> m;

    ll res = powmod(10, n, m);
    res -= (res / 10);
    res /= k;

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
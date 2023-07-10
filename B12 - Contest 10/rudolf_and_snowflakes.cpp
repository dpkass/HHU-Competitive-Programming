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

ld logb_a(ld a, ld b) {
    return log2(a) / log2(b);
}

void solve() {
    ll n;
    cin >> n;

    ld logval = 2, res;
    int k = 2;
    while (logval >= 2) {
        logval = logb_a(n, k);
        if (logval != (ll) logval) logval = (ll) logval;
        else logval = (ll) --logval;

        res = (1.0 - pow(k, logval + 1)) / (1.0 - k);
        if (res == n) break;
        k++;
    }

    if (logval >= 2) print("Yes");
    else print("No");
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
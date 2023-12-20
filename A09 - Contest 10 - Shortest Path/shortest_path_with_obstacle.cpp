//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define all(coll) coll.begin(), coll.end()
#define print(i) cout << i << endl
#define print_coll(a) for(auto item: a) cout << item << ' '

//#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef set<int> si;

bool sorted(int a, int b, int c) {
    return a < b && b < c || a > b && b > c;
}

void solve() {
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;
    print(abs(xa - xb) + abs(ya - yb) +
          2 * (xa == xb && xa == xf && sorted(ya, yf, yb) || ya == yb && ya == yf && sorted(xa, xf, xb)));
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
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

//#define int ll

void solve() {
    string s, _;
    cin >> _ >> s;

    char c, p = s[1], pp = s[0];
    ll count = 1;
    for (int i = 2; i < s.size(); ++i) {
        c = s[i];
        if (c != p && c != pp) count++;
        else if (c != pp) count++;
        pp = p;
        p = c;
    }

    print(count);
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
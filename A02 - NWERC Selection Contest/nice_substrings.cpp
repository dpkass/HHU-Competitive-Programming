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

ll count_changes(string s, ll piv) {
    ll z_to_piv = count(s.begin(), s.begin() + piv, '0');
    ll o_to_piv = count(s.begin(), s.begin() + piv, '1');
    ll z_after_piv = count(s.begin() + piv, s.end(), '0');
    ll o_after_piv = count(s.begin() + piv, s.end(), '1');
    return min(z_to_piv, o_to_piv) + min(z_after_piv, o_after_piv);
}

void solve() {
    string s;
    cin >> s;

    ll minv = LLONG_MAX, mini = 0, maxv = LLONG_MIN, maxi = 0, prev = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '1' && ++prev > maxv) {
            maxv = prev;
            maxi = i + 1;
        } else if (s[i] == '0' && --prev < minv) {
            minv = prev;
            mini = i + 1;
        }
    }

    print(min(count_changes(s, mini), count_changes(s, maxi)));
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
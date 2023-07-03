//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define pb push_back
#define print(i) cout << i << endl
#define print_col(a) for(auto item: a) cout << item << ' '

#define int ll
#define half(i) ((i + 1) / 2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector <pi> vii;
typedef set<int> si;
typedef set<pi> sii;

void solve() {
    int n;
    ll W;
    cin >> n >> W;

    ll W2 = half(W);
    int i = 1e18;

    auto cmp = [](pi a, pi b) { return a.first < b.first; };
    multiset<pi, decltype(cmp)> items(cmp);
    for (int i = 1, x; i <= n; ++i)
        cin >> x, items.insert({x, i});

    auto gt_e_lt_W = items.lower_bound({W + 1, 0});
    if (gt_e_lt_W != items.end() && gt_e_lt_W->first >= W2 && gt_e_lt_W->first <= W) {
        print(1);
        print(gt_e_lt_W->second);
        return;
    }

    items.erase(gt_e_lt_W, items.end());
    ll sum = 0;

    vi ans;
    for (auto it = items.rbegin(); sum < W2 && it != items.rend(); ++it)
        sum += it->first, ans.pb(it->second);

    if (sum < W2) {
        print(-1);
        return;
    }

    print(ans.size());
    print_col(ans);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("10 - Contest 8/test.in", "r", stdin);
    freopen("10 - Contest 8/test.out", "w", stdout);
#endif

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
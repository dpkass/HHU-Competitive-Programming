//
// Created by dpkass
// ID - NAME
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
typedef set<pi> sii;

int pop_last(si &s) {
    auto lastit = s.end();
    int val = *(--lastit);
    s.erase(lastit);
    return val;
}

void solve() {
    int n, m;
    cin >> n >> m;

    sii e;
    for (int i = 0, x, y; i < m; ++i)
        cin >> x >> y, e.emplace(x, y);

    vi nums(n);
    iota(all(nums), 1);

    si nodes(all(nums)), reached;
    int count = -1;
    while (!nodes.empty()) {
        int u;
        if (!reached.empty()) u = pop_last(reached);
        else u = pop_last(nodes), count++;

        si reached_it;
        for (auto v: nodes) {
            if (e.count({u, v}) || e.count({v, u})) continue;
            reached_it.insert(v);
        }

        si remaining;
        set_difference(all(nodes), all(reached_it), inserter(remaining, remaining.end()));

        nodes = remaining;
        reached.insert(all(reached_it));
    }

    print(count);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
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

map<int, vi> make_tree(map<int, vi> edges) {
    map<int, vi> tree;
    map<int, int> parent;
    parent[1] = 1;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int from = q.front();
        q.pop();
        for (const auto &to: edges[from])
            if (to != parent[from]) {
                tree[from].push_back(to);
                parent[to] = from;
                q.push(to);
            }
    }

    return tree;
}

int children(map<int, int> &memo, map<int, vi> &tree, int x) {
    if (memo.count(x)) return memo[x];

    if (tree[x].empty()) return memo[x] = 1;

    int counter = 0;
    for (const auto &to: tree[x])
        counter += children(memo, tree, to);

    return memo[x] = counter;
}

void solve() {
    int n;
    cin >> n;

    map<int, vi> edges;

    for (int i = 1, x, y; i < n; ++i)
        cin >> x >> y, edges[x].push_back(y), edges[y].push_back(x);

    map<int, vi> tree = make_tree(edges);

    map<int, int> memo;

    int q;
    cin >> q;
    for (int i = 0, x, y; i < q; ++i) {
        cin >> x >> y;
        print(children(memo, tree, x) * children(memo, tree, y));
    }
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
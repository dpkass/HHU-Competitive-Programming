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
#define print_col(a) for(auto item: a) cout << item << ' '

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef set<int> si;

int backedge_count = 0;
vi color;
map<int, vi> edges;

void dfs(int i, int par) {
    color[i] = 1;

    for (const auto to: edges[i]) {
        if (to == par || color[to] == 2) continue;

        if (color[to] == 1) backedge_count++;
        else dfs(to, i);

        if (backedge_count > 2) return;
    }

    color[i] = 2;
}

void solve() {
    int n, m;
    cin >> n >> m;

    color = vi(n + 1, 0);
    color[0] = 2;

    for (int i = 0, x, y; i < m; ++i)
        cin >> x >> y, edges[x].push_back(y), edges[y].push_back(x);

    dfs(1, 0);

    if (backedge_count != 1 || any_of(all(color), [](int i) { return i != 2; })) print("NO");
    else print("FHTAGN!");
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
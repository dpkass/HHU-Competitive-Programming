//
// Created by dpkass
// doesn't work

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
typedef vector<bool> vb;
typedef set<int> si;

map<int, vi> g;
set<pi> has_art;
vi color;
int dealer;

void dfs(int from, bool carries_art) {
    color[from] = 1;

    for (const int to: g[from]) {
        if (color[to] == 1) continue;

    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    color.assign(n + 1, 0);

    for (int i = 0, x, y, z; i < m; ++i)
        cin >> x >> y >> z,
                g[x + 1].push_back(y + 1),
                g[y + 1].push_back(x + 1),
                has_art.insert({x + 1, y + 1});

    int start;

    cin >> start >> dealer;

    dfs(start, false);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define timestart clock_t begin = clock();
#define timeend \
  clock_t end = clock(); \
  double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC; \
  print("took " << elapsed_secs << "sec")

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef set<int> si;
typedef list<int> li;
typedef queue<int> qi;

void print_ans(vi &v) {
    print(v.size() << endl);
    for (const auto i: v) print(i << ' ');
    print(endl);
}

#define other(i) (i == 1 ? 2 : 1)
#define is_set(i) (i == 1 || i == 2)
#define not_set(i) !is_set(i)

bool bfs_rek(map<int, vi> *adj_l, vi &belongs, si &nodes, vi q, int color) {
    if (q.empty()) return false;

    vi next;
    for (int v: q) {
        if (belongs[v] == other(color)) return true;
        belongs[v] = color;
        nodes.erase(v);

        next.insert(next.end(), (*adj_l)[v].begin(), (*adj_l)[v].end());
        adj_l->erase(v);
    }

    return bfs_rek(adj_l, belongs, nodes, next, other(color));
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, vi> adj_l;
    si nodes;

    for (int i = 0, x, y; i < m; ++i)
        cin >> x >> y,
                adj_l[x].pb(y),
                adj_l[y].pb(x),
                nodes.insert(x),
                nodes.insert(y);

    vi belongs(n + 1, 0);

    bool error = false;
    while (!nodes.empty() && !error)
        error = bfs_rek(&adj_l, belongs, nodes, vi{adj_l.begin()->first}, 1);

    if (error) {
        print(-1);
        return;
    }

    vi a, b;
    for (int i = 1; i <= n; ++i) {
        if (belongs[i] == 1) a.pb(i);
        else if (belongs[i] == 2) b.pb(i);
    }

    print_ans(a);
    print_ans(b);
}

int main() {
    Speed;

    freopen("Testers/test2.txt", "r", stdin);

    solve();

    return 0;
}
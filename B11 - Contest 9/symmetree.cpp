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
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

map<int, vi> all_edges;
map<int, vi> tree;
vb matched;

void read_edges() {
    int n;
    cin >> n;

    all_edges.clear();
    tree.clear();
    matched.resize(n + 1);
    fill(matched.begin(), matched.end(), false);

    for (int i = 0, a, b; i < n - 1; ++i)
        cin >> a >> b, all_edges[a].pb(b), all_edges[b].pb(a);

    // root
    all_edges[1].pb(0);
}

void to_tree(int node, int par) {
    for (int i: all_edges[node])
        if (i != par) {
            tree[node].pb(i);
            to_tree(i, node);
        }
}

bool compare(vi &left, vi &right) {
    int count_matches = 0;

    int size = left.size();

    for (int i: left) {
        for (int j: right) {
            if (tree[i].size() != tree[j].size()
                || matched[i]
                || matched[j])
                continue;

            if (tree[i].size() == 2 || compare(tree[i], tree[j]))
                matched[i] = matched[j] = true, count_matches++;
        }
    }

    return size == count_matches;
}

bool compare(vi &nodes) {
    int count_matches = 0;

    int size = nodes.size();

    for (int i: nodes) {
        for (int j: nodes) {
            if (i == j
                || tree[i].size() != tree[j].size()
                || matched[i]
                || matched[j])
                continue;

            if (tree[i].size() == 2 || compare(tree[i], tree[j]))
                matched[i] = matched[j] = true, count_matches += 2;
        }
    }

    if (size % 2 == 0 || size > count_matches + 1) return size == count_matches;

    for (int i: nodes)
        if (!matched[i]) return compare(tree[i]);
}

void solve() {
    read_edges();
    to_tree(1, 0);

    if (compare(tree[1])) print("Yes");
    else print("No");
}

signed main() {
    Speed;

    freopen("in", "r", stdin);

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
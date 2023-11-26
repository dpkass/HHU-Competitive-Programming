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
typedef set<int> si;

map<int, si> make_tree(map<int, vi> m) {
    map<int, si> tree;
    map<int, int> parent;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int from = q.front();
        q.pop();

        for (const auto &item: m[from]) {
            if (item != parent[from]) {
                tree[from].insert(item);
                parent[item] = from;
                q.push(item);
            }
        }
    }

    return tree;
}

int find_first_leaf(map<int, si> tree, int root) {
    queue<int> q, next;
    q.push(root);

    int counter = 1;

    while (true) {
        while (!q.empty()) {
            if (tree.count(q.front()))
                for (const auto &item: tree[q.front()]) next.push(item);
            else return counter;
            q.pop();
        }
        if (next.empty()) break;

        q = next;
        next = queue<int>();
        counter++;
    }

    return counter;
}

int count_lower(map<int, si> &tree, int from_depth, int start) {
    queue<int> q, next;
    q.push(start);

    int counter = 0;
    int depth = 1;

    while (true) {
        while (!q.empty()) {
            if (tree.count(q.front()))
                for (const auto &item: tree[q.front()]) next.push(item);
            if (depth > from_depth)
                counter++;
            q.pop();
        }
        if (next.empty()) break;

        q = next;
        next = queue<int>();
        depth++;
    }

    return counter;
}

void solve() {
    int n;
    cin >> n;

    map<int, vi> m;

    for (int i = 0, x, y; i < n - 1; ++i)
        cin >> x >> y, m[x].push_back(y), m[y].push_back(x);

    map<int, si> tree = make_tree(m);

    int depth_r, depth_l;
    depth_l = find_first_leaf(tree, *(tree[1].begin()));
    depth_r = find_first_leaf(tree, *(--tree[1].end()));

    depth_l = min(depth_l, depth_r - 1);
    depth_r = depth_l + 1;

    print(count_lower(tree, depth_l, *(tree[1].begin()))
          + count_lower(tree, depth_r, *(--tree[1].end())));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif
    solve();

    return 0;
}
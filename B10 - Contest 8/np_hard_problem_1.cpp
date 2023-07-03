//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef set<int> si;

bool intersects(const si &a, const si &b) {
    vi is;
    is.reserve(min(a.size(), b.size()));
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(is));
    return !is.empty();
}

bool insert_with_check(si &to, const si &contains_from, si *not_contains_from) {
    if (intersects(contains_from, to))
        return false;

    not_contains_from->merge(to);
    return true;
}

bool split(map<int, si> &adj_l, si &a, si &b) {
    map<int, si> skipped;

    for (auto &[from, to]: adj_l) {
        bool res = true;
        if (a.count(from))
            res = insert_with_check(to, a, &b);
        else if (b.count(from))
            res = insert_with_check(to, b, &a);
        else {
            bool a_to = intersects(a, to), b_to = intersects(b, to);

            if (!a_to && !b_to) skipped[from] = to;
            else if (!b_to) {
                b.insert(from);
                a.merge(to);
            } else if (!a_to) {
                a.insert(from);
                b.merge(to);
            } else return true;
        }

        if (!res) return true;
    }

    adj_l = skipped;
    return false;
}

void print_ans(si &set) {
    print(set.size() << endl);
    for (const auto i: set) print(i << ' ');
    print(endl);
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, si> adj_l;
    for (int i = 0, a, b; i < m; ++i)
        cin >> a >> b, adj_l[min(a, b)].insert(max(a, b));

    si a, b;
    a.insert(adj_l.begin()->first);

    bool error = false;

    while (!adj_l.empty() && !error)
        error = split(adj_l, a, b);

    if (error)
        print(-1);
    else {
        print_ans(a);
        print_ans(b);
    }
}

int main() {
    Speed;

    solve();

    return 0;
}
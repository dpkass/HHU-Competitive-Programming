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
typedef vector<pair<int, int>> vii;
typedef set<int> si;

int insert(si &a, si &b, int x, int y) {
    size_t ax = a.count(x), ay = a.count(y), bx = b.count(x), by = b.count(y);
    if (ax && ay || bx && by)
        return -1;

    if (ax) b.insert(y);
    else if (ay) b.insert(x);
    else if (bx) a.insert(y);
    else if (by) a.insert(x);
    else return 0;

    return 1;
}

void print_ans(si &set) {
    print(set.size() << endl);
    for (const auto i: set) print(i << ' ');
    print(endl);
}

int main() {
    Speed;

    int n, m;
    cin >> n >> m;

    si a, b;
    vector<pair<int, int>> e;

    int x, y;
    cin >> x >> y;
    a.insert(x);
    b.insert(y);

    for (int i = 1; i < m; ++i)
        cin >> x >> y, e.emplace_back(x, y);


    while (!e.empty()) {
        vii skipped;
        for (const auto [x, y]: e) {
            int i = insert(a, b, x, y);

            if (i == -1) {
                print(-1);
                return 0;
            } else if (i == 0) {
                skipped.emplace_back(x, y);
            }
        }

        if (e.size() == skipped.size()) {
            auto temp = skipped.end() - 1;
            a.insert(temp->first);
            b.insert(temp->second);
            skipped.pop_back();
        }
        e = skipped;
    }

    print_ans(a);
    print_ans(b);

    return 0;
}
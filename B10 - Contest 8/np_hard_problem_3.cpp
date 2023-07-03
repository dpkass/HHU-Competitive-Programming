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

void print_ans(vi &v) {
    print(v.size() << endl);
    for (const auto i: v) print(i << ' ');
    print(endl);
}

#define other(i) (i == 1 ? 2 : 1)
#define is_set(i) (i == 1 || i == 2)
#define not_set(i) !is_set(i)

vector<int> &split_not_set(vector<int> &belongs, const vii &not_set_v, const int x, const int y_val) {
    auto [x1, y1] = not_set_v[belongs[x]];
    int z = x == x1 ? y1 : x1;
    belongs[z] = y_val;
    belongs[x] = other(y_val);
    return belongs;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vii e;

    for (int i = 0, x, y; i < m; ++i)
        cin >> x >> y, e.emplace_back(x, y);

    vector<int> belongs(n + 1, 0);

    belongs[e[0].first] = 1;
    belongs[e[0].second] = 2;

    vii not_set_v(n + 2);

    int i = 3;
    for (const auto [x, y]: e) {
        if (belongs[x] == 0 && belongs[y] == 0) belongs[x] = i, belongs[y] = i, not_set_v[i++] = {x, y};
        else if (belongs[x] >= 3 && is_set(belongs[y])) belongs = split_not_set(belongs, not_set_v, x, belongs[y]);
        else if (belongs[y] >= 3 && is_set(belongs[x])) belongs = split_not_set(belongs, not_set_v, y, belongs[x]);
        else if (belongs[x] >= 3 && belongs[y] >= 3);
        else if (is_set(belongs[x]) && not_set(belongs[y])) belongs[y] = other(belongs[x]);
        else if (is_set(belongs[y]) && not_set(belongs[x])) belongs[x] = other(belongs[y]);
        else if (belongs[x] == belongs[y]) {
            print(-1);
            return;
        }
    }

    vi a, b;
    for (int i = 1; i <= n; ++i) {
        if (belongs[i] == 1) a.push_back(i);
        else if (belongs[i] == 2) b.push_back(i);
        else if (belongs[i] >= 3) belongs = split_not_set(belongs, not_set_v, i, 1);
    }

    print_ans(a);
    print_ans(b);
}

// doesnt quite work, but very fast
int main() {
    Speed;

//    freopen("Testers/test3.txt", "r", stdin);

    solve();

    return 0;
}
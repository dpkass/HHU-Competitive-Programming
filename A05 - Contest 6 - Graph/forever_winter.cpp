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

void solve() {
    ll n, m;
    cin >> n >> m;

    vi edge_sides(n, 0);
    for (int i = 0, x; i < m * 2; ++i)
        cin >> x, edge_sides[x - 1]++;

    int num1 = 1, num2 = -1;
    for (const auto &node: edge_sides)
        if (node != 1) {
            if (num1 == 1) num1 = node;
            else if (num1 != node) num2 = node;
        }

    if (num2 == -1) {
        print(num1 << ' ' << num1 - 1);
        return;
    }

    ll num1_count = count_if(edge_sides.begin(), edge_sides.end(), [num1](int x) { return x == num1; });
    if (num1_count > 1) print(num2 << ' ' << num1 - 1);
    else
        print(num1 << ' ' << num2 - 1);
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
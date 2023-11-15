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

#define diff(i) = abs(heights[i] - heights[i + 1])

void solve() {
    ll n;
    cin >> n;

    vi heights(n);
    for (int i = 0, x; i < n; ++i)
        cin >> heights[i];

    ll min_diff = abs(heights[0] - heights[n - 1]), min_index = n - 1;
    for (int i = 0; i < n - 1; ++i) {
        ll diff = abs(heights[i] - heights[i + 1]);
        if (diff < min_diff) {
            min_diff = diff;
            min_index = i;
        }
    }

    print(min_index + 1 << ' ' << ((min_index + 1) % n) + 1);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
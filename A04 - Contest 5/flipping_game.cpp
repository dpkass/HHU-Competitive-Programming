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
    int n;
    cin >> n;

    int ones;
    vi vals(n);
    for (int i = 0; i < n; ++i)
        cin >> vals[i], ones += vals[i];

    if (ones == n) {
        print(n - 1);
        return;
    }

    int max = 0, diff = 0;
    for (int val: vals) {
        if (val) diff--;
        else diff++;

        if (diff > max) max = diff;
        else if (diff < 0) diff = 0;
    }

    print(ones + max);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
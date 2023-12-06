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
typedef set<int> si;

void solve() {
    int k;
    cin >> k;

    print("YES");

    if (k == 1) {
        print(2 << ' ' << 1);
        print(1 << ' ' << 2);
        return;
    }

    print(k + 2 << ' ' << (k + 2) * k);

    for (int i = 3; i <= k + 1; ++i)
        print(1 << ' ' << i);
    for (int i = 2; i <= k + 2; ++i)
        for (int j = 2; j <= k + 2; ++j)
            if (i != j)
                print(i << ' ' << j);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
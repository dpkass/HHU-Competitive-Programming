//
// Created by dpkass
//

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

int solve() {
    int h1, h2, a, b;
    cin >> h1 >> h2 >> a >> b;

    h2 -= h1 + 8 * a;
    if (h2 <= 0) return 0;
    else if (a <= b) return -1;
    else return ceil(h2 / (12. * (a - b)));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    print(solve());

    return 0;
}
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

#define odd(i) (i % 2 == 1)

int solve(int n, int m) {
    if (m == n)
        return 0;
    else if (m < n)
        return n - m;
    else {
        int c = 1;
        if (odd(m)) m++, c++;
        return c + solve(n, m / 2);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    print(solve(n, m));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
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

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    vi points(n, 0), penalties(n, 0);
    for (int i = 0; i < n; ++i) {
        vi ti(m);
        for (int j = 0; j < m; ++j) cin >> ti[j];
        sort(ti.begin(), ti.end());

        int time = 0;
        for (int tij: ti)
            if (tij + time <= h)
                time += tij,
                        penalties[i] += time,
                        points[i]++;
            else break;
    }

    int better = 1;
    for (int i = 1; i < n; ++i)
        if (points[i] > points[0] ||
            points[i] == points[0] && penalties[i] < penalties[0])
            better++;

    print(better);
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
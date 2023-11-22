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
    int n, d;
    string s;
    cin >> n >> d >> s;

    int i = 0, counter = 0, last = -1;
    while (i < n - 1) {
        if (i <= last) {
            print(-1);
            return;
        }

        char c = s[i];
        if (c == '1')
            last = i, i += d, counter++;
        else i--;
    }

    print(counter);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
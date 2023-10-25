//
// Created by keko
//

#include <bits/stdc++.h>

using namespace std;

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
typedef multiset<int> msi;
typedef multiset<pi> msii;

void solve() {
    int n;
    cin >> n;

    string map[n];

    for (int i = 0; i < n; i++) cin >> map[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            short c = 0;
            if (i > 0 && map[i - 1][j] == 'o') c++;
            if (j > 0 && map[i][j - 1] == 'o') c++;
            if (i < n - 1 && map[i + 1][j] == 'o')c++;
            if (j < n - 1 && map[i][j + 1] == 'o') c++;

            if (c % 2) {
                print("NO");
                return;
            }
        }
    }
    print("YES");
}

signed main() {

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
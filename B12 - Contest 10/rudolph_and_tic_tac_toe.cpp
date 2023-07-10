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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

//#define int ll

bool vertical(char field[3][3], int i) {
    if (field[0][i] == field[1][i] && field[1][i] == field[2][i] && field[0][i] != '.') {
        print(field[0][i]);
        return true;
    }
    return false;
}

bool horizontal(char field[3][3], int i) {
    if (field[i][0] == field[i][1] && field[i][1] == field[i][2] && field[i][0] != '.') {
        print(field[i][0]);
        return true;
    }
    return false;
}

bool diagonal(char field[3][3]) {
    if ((field[0][0] == field[1][1] && field[1][1] == field[2][2] ||
         field[0][2] == field[1][1] && field[1][1] == field[2][0]) &&
         field[1][1] != '.') {
        print(field[1][1]);
        return true;
    }
    return false;
}

void solve() {
    char field[3][3];

    char x;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> x, field[i][j] = x;

    for (int i = 0; i < 3; ++i)
        if (vertical(field, i)) return;
    for (int i = 0; i < 3; ++i)
        if (horizontal(field, i)) return;
    if (diagonal(field)) return;

    print("DRAW");
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
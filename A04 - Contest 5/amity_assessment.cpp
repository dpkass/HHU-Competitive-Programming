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

string read_clockwise() {
    string s, temp;
    for (int i = 0; i < 4; ++i) {
        char c;
        cin >> c;
        if (c == 'X') continue;

        if (i == 0) s += c;
        if (i == 1) s += c;
        if (i == 2) temp = c;
        if (i == 3) s += c;
    }

    s += temp;
    return s;
}

string shift(string s, char c) {
    int i = s.find(c);
    return string(s.begin() + i, s.end()) + string(s.begin(), s.begin() + i);
}

void solve() {
    string a, b;
    a = read_clockwise();
    b = read_clockwise();
    b = shift(b, a[0]);
    print((a == b ? "YES" : "NO"));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
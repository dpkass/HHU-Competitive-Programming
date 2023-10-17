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
typedef multiset<int> msi;
typedef multiset<pi> msii;

map<char, int> degree = {{'E', 90},
                         {'S', 180},
                         {'W', 270}};

ld calc_degrees(const string &s) {
    degree['N'] = s.find('W') == string::npos ? 0 : 360;

    const char main_dir = s[s.length() - 1];
    ld deg = degree[main_dir];

    ld change = 90;

    for (auto c = s.rbegin(); c < s.rend(); ++c) {
        if (degree[*c] > deg) deg += change;
        else if (degree[*c] < deg) deg -= change;
        change /= 2;
    }

    return deg;
}

void solve() {
    string x, y;
    cin >> x >> y;

    ld x_deg = calc_degrees(x);
    ld y_deg = calc_degrees(y);

    cout.precision(20);
    print(min(abs(x_deg - y_deg), 360 - abs(x_deg - y_deg)));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
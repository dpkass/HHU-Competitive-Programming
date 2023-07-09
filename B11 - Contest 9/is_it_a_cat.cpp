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

void solve() {
    int n;
    string s;

    cin >> n >> s;

    if (tolower(s[0]) != 'm' || tolower(s[n - 1]) != 'w') {
        print("No");
        return;
    }

    char curr = 'm';
    for (char c: s) {
        c = tolower(c);
        if (curr == c) continue;
        if (curr == 'm' && c == 'e') curr = 'e';
        else if (curr == 'e' && c == 'o') curr = 'o';
        else if (curr == 'o' && c == 'w') curr = 'w';
        else {
            print("No");
            return;
        }
    }

    print("Yes");
}

signed main() {
    Speed;

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
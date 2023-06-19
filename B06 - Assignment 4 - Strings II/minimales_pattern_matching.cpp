//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i
#define ll long long

void solve() {
    string s;
    cin >> s;

    char prev = '0';

    for (char c: s) {
        if (c != '?')
            prev = c;
        print(prev);
    }

    print(endl);
}

int main() {
    Speed;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
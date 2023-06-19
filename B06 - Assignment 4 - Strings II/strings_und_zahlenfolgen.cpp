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
#define ll long long

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    char curr = s[0];
    int longest = 0, counter = 0;

    for (char c: s) {
        if (c == curr) counter++;
        else {
            longest = max(longest, counter);
            counter = 1;
            curr = c;
        }
    }

    print(max(longest, counter) + 1);
}

int main() {
    Speed;

    #ifndef ONLINE_JUDGE
    freopen("06 - Assignment 4 - Strings II/test1.txt", "r", stdin);
    freopen("06 - Assignment 4 - Strings II/out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
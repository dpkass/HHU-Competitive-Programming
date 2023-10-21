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

string mirrorable = "AHIMOTUVWXY";

bool is_palindrome(const string &s) {
    string rev(s);
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < s.length() / 2 + 1; ++i)
        if (s[i] != rev[i])
            return false;
    return true;
}

bool only_mirrorable_chars(string &s) {
    return all_of(s.begin(), s.end(), [&](char c) { return mirrorable.find(c) != std::string::npos; });
}

void solve() {
    string s;
    cin >> s;

    if (!is_palindrome(s) || !only_mirrorable_chars(s))
        print("NO");
    else
        print("YES");
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
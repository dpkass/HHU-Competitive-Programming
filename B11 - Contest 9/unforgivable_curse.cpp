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

const int c_arr = 'z' + 1;


bool check_count(const string &s, const string &t) {
    vi s_chars(c_arr, 0), t_chars(c_arr, 0);
    for (char c: s) s_chars[c]++;
    for (char c: t) t_chars[c]++;

    for (int i = 'a'; i < c_arr; ++i)
        if (s_chars[i] != t_chars[i]) return false;

    return true;
}

bool check_equal_middle(const string &s, const string &t, int start, int stop) {
    while (start < stop) {
        if (s[start] != t[start]) return false;
        start++;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;

    string s, t;
    cin >> s >> t;

    if (s == t) print("Yes");
    else if (n < k) print("No");
    else if (!check_count(s, t)) print("No");
    else if (!check_equal_middle(s, t, n - k, k)) print("No");
    else print("Yes");
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
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
    int n, k;
    string s;
    cin >> n >> k >> s;

    vi count('z' + 1, 0);
    for (char c: s) count[c]++;

    int pairs = 0, non_pairs = 0;
    for (char curr_l = 'a', curr_u = 'A'; curr_l <= 'z'; curr_l++, curr_u++) {
        int match = min(count[curr_l], count[curr_u]);
        pairs += match;
        non_pairs += (max(count[curr_l], count[curr_u]) - match) / 2;
    }

    print(pairs + min(non_pairs, k));
}

signed main() {
    Speed;

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
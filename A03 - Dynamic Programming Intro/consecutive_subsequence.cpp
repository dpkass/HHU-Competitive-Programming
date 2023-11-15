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

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef list<int> li;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

vi vals;
vi memo;
vi len;

li reconstruct_memo(int i) {
    li res;
    while (i != -1) {
        res.push_front(i + 1);
        i = memo[i];
    }
    return res;
}

ll lcs(int i) {
    if (len[i]) return len[i];
    else len[i] = 1;

    for (int j = i - 1; j >= 0; --j)
        if (vals[i] == vals[j] + 1) {
            len[i] = lcs(j) + 1;
            memo[i] = j;
            break;
        }

    return len[i];
}

void solve() {
    ll n;
    cin >> n;

    memo.assign(n, -1);
    len.assign(n, 0);

    vals.reserve(n);
    for (int i = 0, x; i < n; ++i)
        cin >> x, vals.push_back(x);

    len[0] = 1;
    ll max_i = 0;
    for (int i = n - 1; i >= 0; --i)
        if (lcs(i) > len[max_i])
            max_i = i;

    print(len[max_i]);
    print_col(reconstruct_memo(max_i));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define pb push_back
#define print(i) cout << i << endl
#define print_col(a) for(auto item: a) cout << item << ' '

#define int ll
#define half(i) ((i + 1) / 2)
#define in_range(i) (i <= W && i >= W2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

void solve() {
    int n;
    ll W;
    cin >> n >> W;

    ll W2 = half(W);
    int sum = 0;

    vi ans;
    for (int i = 1, x; i <= n && sum < W2; ++i) {
        cin >> x;
        if (sum + x <= W) {
            sum += x;
            ans.pb(i);
        } else if (in_range(x)) {
            print(1);
            print(i);
            return;
        }
    }

    if (in_range(sum)){
        print(ans.size());
        print_col(ans);
    } else {
        print(-1);
    }
}

signed main() {
    Speed;

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
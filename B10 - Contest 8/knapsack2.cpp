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

const int n = 8;

ll max_w;
ll cnt[n + 1], available[n + 1];

ll reduce(ll sum, int pos) {
    ll diff = sum - max_w;
    if (cnt[1] - available[1] >= diff) return sum - diff;

    ll res = sum - pos;
    for (int i = 1; i < (1 << n); ++i) {
        ll new_sum = sum;
        bitset<n> rem(i);

        for (int j = 1; j <= n; ++j) if (rem[j] && cnt[j] != available[j]) new_sum -= j;

        if (new_sum == sum) continue;
        if (new_sum > max_w) new_sum = reduce(new_sum, pos);
        if (new_sum == max_w) return new_sum;
        else if (new_sum > res) res = new_sum;
    }

    return res;
}

void solve() {
    cin >> max_w;

    for (ll i = 1, x; i <= n; ++i)
        cin >> x, available[i] = cnt[i] = x;

    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        ll max_take = min(((max_w - sum) / i) + 1, cnt[i]);

        sum += max_take * i;
        available[i] -= max_take;

        if (sum > max_w) sum = reduce(sum, i);
        if (sum == max_w) break;
    }

    print(sum);
}

int main() {
    Speed;

    solve();

    return 0;
}

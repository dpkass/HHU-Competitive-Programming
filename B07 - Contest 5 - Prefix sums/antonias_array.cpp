//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << ' '

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;

void prefix_sum(vi &arr) {
    for (ll i = 1; i < arr.size(); ++i)
        arr[i] += arr[i - 1];
}

int main() {
    Speed;

    ll n, m, k;
    cin >> n >> m >> k;

    // init arr
    vi arr(n);
    for (ll i = 0; i < n; ++i)
        cin >> arr[i];

    // ops
    vi l(m), r(m), d(m);
    for (ll i = 0; i < m; ++i)
        cin >> l[i] >> r[i] >> d[i];

    // queries as difference array
    vi queries(m + 1, 0);
    for (ll x, y; k--;) {
        cin >> x >> y;
        queries[x - 1]++;
        queries[y]--;
    }


    // prefix sum queries - gives how often operation i should be repeated
    prefix_sum(queries);

    // weighted difference array - diff array multiplied by occurrence of each in op in queries
    ll val;
    vi weighted_diff(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        val = queries[i] * d[i];
        weighted_diff[l[i] - 1] += val;
        weighted_diff[r[i]] -= val;
    }

    // weighted prefix sum - add to init arr
    prefix_sum(weighted_diff);


    for (int i = 0; i < n; ++i)
        print(arr[i] + weighted_diff[i]);
    cout << endl;

    return 0;
}
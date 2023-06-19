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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

void prefix_sum(ll arr[], ll ps_arr[], int n) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        ps_arr[i] = sum;
    }
}

ll get_value(const ll *arr, int l, int r) { arr[r - 1] - (l == 1 ? 0 : arr[l - 2]); }

int main() {
    Speed;

    int n;
    cin >> n;

    ll arr[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    ll ps_arr[n];
    ll ps_sorted_arr[n];

    prefix_sum(arr, ps_arr, n);

    sort(arr, arr + n);
    prefix_sum(arr, ps_sorted_arr, n);

    int m;
    cin >> m;
    int type, l, r;
    ll *use;
    while (m--) {
        cin >> type >> l >> r;
        use = type == 1 ? ps_arr : ps_sorted_arr;
        print(get_value(use, l, r));
    }

    return 0;
}

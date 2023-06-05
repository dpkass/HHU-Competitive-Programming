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
    int n, m;
    cin >> n;
    m = n;

    int zero_counter = 0;
    bool has_1 =false;
    bool has_other_nums = false;

    int x;
    while (m--) {
        cin >> x;
        if (x == 0) zero_counter++;
        else if (x == 1) has_1 =true;
        else has_other_nums = true;
    }

    if (zero_counter * 2 <= n + 1) print(0);                // less than half + 1 are 0s
    else if (!has_1 || has_other_nums)                      // no 1s or 1s and other nums
        print(1);
    else
        print(2);
}

// case [..., 0+1]/[0, ..., 0] or [..., 0+x, (1),...], x>1
int main() {
    Speed;

    int t;
    cin >> t;

    while (t--) solve();

    return 0;
}
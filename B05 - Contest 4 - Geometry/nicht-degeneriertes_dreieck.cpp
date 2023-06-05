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

int main() {
    Speed;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int nums[n];
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        if (nums[0] + nums[1] <= nums[n - 1]) print(1 << ' ' << 2 << ' ' << n);
        else
            print(-1);
    }

    return 0;
}
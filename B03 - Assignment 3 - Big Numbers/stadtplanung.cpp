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

    int n;
    cin >> n;

    int nums[n];

    int even1 = 0, odd1 = 0;
    int even2 = 0, odd2 = 0;

    for (int i = 0; i < n; ++i)
        cin >> nums[i];

    for (int i = 0; i < n; i += 2)
        if (nums[i] % 2) odd1++;
        else even1++;

    for (int i = 1; i < n; i += 2)
        if (nums[i] % 2) odd2++;
        else even2++;

    print(min(even1, odd1) + min(even2, odd2));

    return 0;
}
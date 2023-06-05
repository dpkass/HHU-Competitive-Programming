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

    int n, h;
    cin >> n >> h;

    cout.precision(20);
    for (double i = 1; i < n; i++)
        cout << h * sqrt(i / n) << ' ';

    return 0;
}
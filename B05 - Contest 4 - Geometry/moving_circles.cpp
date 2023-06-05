#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define ll long long
#define ld long double

int main() {
    Speed;

    int r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;

    ll x_diff = x1 - x2;
    ll y_diff = y1 - y2;
    ld dist = sqrt(x_diff * x_diff + y_diff * y_diff);

    print(ceil(dist / (r * 2)));

    return 0;
}
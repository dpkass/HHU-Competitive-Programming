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

int main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("07 - Contest 5 - Prefix sums/test.txt", "r", stdin);
    freopen("07 - Contest 5 - Prefix sums/out.txt", "w", stdout);
#endif

    int n, k, q;
    cin >> n >> k >> q;

    vi recipes(200'001, 0);

    int a, b;
    while (n--) {
        cin >> a >> b;
        recipes[a]++;
        recipes[b + 1]--;
    }

    int sum = 0, acc = 0;
    for (int &i: recipes) {
        sum += i;
        if (sum >= k) acc++;
        i = acc;
    }

    while (q--) {
        cin >> a >> b;
        print(recipes[b] - recipes[a - 1]);
    }

    return 0;
}

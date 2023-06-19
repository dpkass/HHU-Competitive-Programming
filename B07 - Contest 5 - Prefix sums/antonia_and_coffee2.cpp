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

//#ifndef ONLINE_JUDGE
//    freopen("07 - Contest 5 - Prefix sums/test.txt", "r", stdin);
//    freopen("07 - Contest 5 - Prefix sums/out.txt", "w", stdout);
//#endif

    int n, k, q;
    cin >> n >> k >> q;

    vi recipes(200'001, 0);

    // try to make a little quicker by just measuring between min and max temp
    int a, b, min_t = 200'000, max_t = 0;
    while (n--) {
        cin >> a >> b;
        recipes[a]++;
        recipes[b + 1]--;
        if (b > max_t) max_t = b;
        if (a < min_t) min_t = a;
    }

    vi prefix(max_t - min_t + 2);
    prefix[0] = 0;

    for (int i = min_t, sum = 0, acc = 0; i <= max_t; ++i) {
        sum += recipes[i];
        if (sum >= k) acc++;
        prefix[i - min_t + 1] = acc;
    }

    while (q--) {
        cin >> a >> b;
        print(prefix[min(max_t, b) - min_t + 1] - prefix[max(min_t, a) - min_t]);
    }

    return 0;
}

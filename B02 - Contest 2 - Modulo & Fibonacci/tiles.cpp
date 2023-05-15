#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define ll long long

ll modpow(int b, int e, int m) {
    if (e == 1) return b;

    int x;
    int e2;

    if (e % 2) {
        x = b;
        e2 = (e - 1) / 2;
    } else {
        x = 1;
        e2 = e / 2;
    }

    ll res = modpow(b, e2, m);
    res %= m;
    res *= res;
    res %= m;
    res *= x;
    res %= m;

    return res;
}

int main() {
    Speed;
    ll res;

    int w, h;
    cin >> w >> h;

    res = modpow(2, w + h, 998244353);

    print(res);
}
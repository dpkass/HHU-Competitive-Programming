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

void solve() {

}

int main() {
    Speed;

    ll a, b;
    cin >> a >> b;

    if (a == 1) {
        print(b);
        return 0;
    }

    ll res = 0;
    while (a > 1) {
        res += b / a;
        b %= a;
        swap(a, b);
    }
    print(res + b);

    return 0;
}
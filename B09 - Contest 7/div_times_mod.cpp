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
    int n, k;
    cin >> n >> k;

    for (int i = min(k - 1, n); i > 0; --i)
        if (n % i == 0) {
            print(k * (n / i) + i);
            break;
        }


    return 0;
}
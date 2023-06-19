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

    int n;
    cin >> n;

    vi in(n);
    for (int i = 0; i < n; ++i)
        cin >> in[i];


    vector<bool> is_out(n, false);
    int fines = 0;
    for (int pos = 0, x; n--;) {
        cin >> x;
        while (is_out[in[pos]]) pos++;
        if (in[pos] != x) fines++;
        is_out[x] = true;
    }

    print(fines);

    return 0;
}
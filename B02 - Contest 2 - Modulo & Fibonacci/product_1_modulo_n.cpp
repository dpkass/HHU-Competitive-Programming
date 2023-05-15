//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i
#define println(i) cout << i << endl
#define ll long long

int main() {
    Speed;

    int n;
    cin >> n;

    vector<int> vals;
    ll prod = 1;

    for (int i = 0; i < n; ++i) {
        if (gcd(n, i) == 1) {
            vals.push_back(i);
            prod = prod * i % n;
        }
    }

    if (prod != 1) vals.pop_back();

    println(vals.size());
    for (int i: vals)
        print(i << ' ');
    println("");

    return 0;
}
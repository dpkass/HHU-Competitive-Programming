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

int gcd(string n, int min) {
    if(min == 1) return 1;

    int smaller_gcd = min;
    for (char &c: n) {
        int _gcd = gcd(min, c - '0');
        if (_gcd < min && _gcd < smaller_gcd)
            smaller_gcd = gcd(n, _gcd);
    }
    if (smaller_gcd != min) return gcd(n, smaller_gcd);
    return min;
}

int main() {
    Speed;

    string n;
    cin >> n;

    int min = n[0];

    for (char &c: n)
        if (c < min)min = c;
    min -= '0';

    print(gcd(n, min));

    return 0;
}
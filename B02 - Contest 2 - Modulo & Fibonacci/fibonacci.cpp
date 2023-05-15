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

int mod = 1000000007;

map<ll, ll> fib;

ll fibonacci(ll n) {
    if (fib.count(n))return fib[n];

    ll k = n / 2;
    ll fib_k = fibonacci(k);
    ll fib_k_1 = fibonacci(k + 1);
    ll fib_n;

    if (n % 2) fib_n = (fib_k_1 * fib_k_1 % mod + fib_k * fib_k % mod) % mod;
    else fib_n = fib_k * ((2 * fib_k_1 - fib_k)) % mod;

    fib[n] = fib_n;
    return fib_n;
}

int main() {
    Speed;

    ll n;
    cin >> n;

    fib[0] = 0;
    fib[1] = fib[2] = 1;
    fibonacci(n);
    print(fib[n] + mod % mod);

    return 0;
}
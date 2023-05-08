#include <iostream>
#include <cmath>

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define print(i) cout << i << endl
#define ll long long

using namespace std;

// t-primes are squares of primes
// check if root is prime

bool is_prime(ll x) {
    if (x < 2) return false;

    for (ll j = 2; j * j <= x; ++j)
        if (x % j == 0)
            return false;
    return true;
}

int main() {
    Speed

    ll n, x, sqrt_x;
    cin >> n;
    while (n--) {
        cin >> x;
        sqrt_x = sqrt(x);

        print((sqrt_x * sqrt_x == x
               && is_prime(sqrt_x)
               ? "YES"
               : "NO"));
    }

    return 0;
}
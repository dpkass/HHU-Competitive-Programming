#include <iostream>
#include <cstring>
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

void get_primes(int n, bool primes[]) {
    memset(primes, 1, n);
    primes[0] = primes[1] = false;

    for (int p = 2; p * p < n; p++)
        if (primes[p])
            for (int i = p * p; i < n; i += p)
                primes[i] = false;
}

int main() {
    Speed

    bool is_prime[1000001];
    get_primes(1000001, is_prime);

    ll n, x, sqrt_x;
    cin >> n;
    while (n--) {
        cin >> x;
        sqrt_x = sqrt(x);

        print((is_prime[sqrt_x]
               && sqrt_x * sqrt_x == x
               ? "YES"
               : "NO"));
    }

    return 0;
}
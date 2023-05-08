#include <iostream>
#include <numeric>
#include <vector>

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);
#define print(i) cout << i << endl
#define ll long long

using namespace std;

// in this case 1 also acts as prime

ll max_div = cbrt(UINT32_MAX) + 1;

void get_primes(ll n, bool primes[]) {
    memset(primes, 1, n);
    primes[0] = false;

    for (int i = 2; i * i < n; i++)
        if (primes[i])
            for (int j = i * i; j < n; j += i)
                primes[j] = false;
}


vector<ll> init_primes() {
    vector<ll> primes;

    bool is_prime[max_div];
    get_primes(max_div, is_prime);

    for (ll i = 0; i < max_div; ++i)
        if (is_prime[i])
            primes.push_back(i);

    return primes;
}

void calc(ll val, vector<ll> primes) {
    for (ll pos = 0;; pos++) {
        ll c = primes[pos];
        if (val % c)
            continue;

        ll rest = val - c;
        ll a = 0, b = rest;
        while (a++ <= b--)
            if (a != c && b != c && gcd(a, b) == c) {
                print(a << ' ' << b << ' ' << c);
                return;
            }
    }
}

int main() {
    Speed

    int n;
    cin >> n;

    vector<ll> primes = init_primes();

    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        calc(val, primes);
    }

    return 0;
}
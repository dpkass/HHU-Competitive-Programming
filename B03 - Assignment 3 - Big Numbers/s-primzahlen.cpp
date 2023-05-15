// siehe almost primes

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define ll long long

void counting_sieve(int n, int prime_div_count[]) {
    for (int i = 2; i <= n; i++)
        if (prime_div_count[i] == 0) // is prime
            for (int j = 2 * i; j < n; j += i)
                prime_div_count[j]++;
}

int count_almost_primes(int n, const int prime_div_count[]) {
    int counter = 0;
    for (int i = 0; i < n; ++i)
        if (prime_div_count[i] == 2)
            counter++;
    return counter;
}

int main() {
    Speed;

    int n;
    cin >> n;

    n++;

    int prime_div_count[n];
    memset(prime_div_count, 0, sizeof(prime_div_count));

    counting_sieve(n, prime_div_count);
    print(count_almost_primes(n, prime_div_count));

    return 0;
}
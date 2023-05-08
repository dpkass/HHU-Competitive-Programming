#include <iostream>
#include <cstring>

using namespace std;

bool is_prime(int i, int prime_div_count[]) {
    return prime_div_count[i] == 0;
}

void count_prime_dividers(int n, int prime_div_count[]) {
    for (int i = 2; i <= n; i++)
        if (is_prime(i, prime_div_count))
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
    int n;
    cin >> n;

    int prime_div_count[n + 1];
    memset(prime_div_count, 0, sizeof(prime_div_count));

    count_prime_dividers(n + 1, prime_div_count);
    cout << count_almost_primes(n + 1, prime_div_count) << endl;

    return 0;
}
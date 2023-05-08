#include <bits/stdc++.h>

using namespace std;

void get_primes(int n, bool primes[]) {
    memset(primes, 1, n);
    primes[0] = primes[1] = false;

    for (int p = 2; p * p < n; p++)
        if (primes[p])
            for (int i = p * p; i < n; i += p)
                primes[i] = false;
}

void print_pair(int n) {
    bool primes[n + 1];
    get_primes(n + 1, primes);
    cout << accumulate(primes, primes + n , 0) << endl;
//    for (int i = 0; i < n; i++) {
//        if (primes[i] && primes[n - i]) {
//            cout << i << ' ' << (n - i) << endl;
//            return;
//        }
//    }
//    cout << -1 << endl;
}

int main() {
    int num = 250000;
//    cin >> num;
    print_pair(num);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

void get_primes(int n, bool primes[]) {
    primes[0] = primes[1] = false;
    for (int i = 2; i < n; i++)
        primes[i] = true;

    for (int p = 2; p * p < n; p++)
        if (primes[p])
            for (int i = p * p; i < n; i += p)
                primes[i] = false;
}

void factorize(int n, bool primes[], vector<int> nums) {
    if (n == 1) return;

    for (int i = 2; i <= n; ++i) {
        if (primes[i] && n % i == 0) {
            nums.push_back(i);
            factorize(n / i, primes, nums);
            return;
        }
    }
}

void print_factors(vector<int> nums) {
    cout << nums[0];
    for (int i = 1, len = nums.size(); i < len; ++i) {
        cout << '*' << nums[i];
    }
    cout << endl;
}

int main() {
    int n = 0;
    cin >> n;

    bool primes[n + 1];
    get_primes(n + 1, primes);

    vector<int> nums;
    factorize(n, primes, nums);
    print_factors(nums);

    return 0;
}

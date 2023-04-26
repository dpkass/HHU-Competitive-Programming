#include <iostream>

using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    cout << (2 * k - 1 <= n ? (k * 2) - 1 : (((k - (n % 2 == 0 ? n / 2 : n / 2 + 1)) * 2))) << endl;

    return 0;
}
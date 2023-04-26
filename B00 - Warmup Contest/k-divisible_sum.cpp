#include <iostream>

int main() {
    int tests;
    std::cin >> tests;

    for (int i = 0; i < tests; ++i) {
        long long n, k;
        std::cin >> n >> k;

        short offset = 1;
        if (n % k != 0) {
            offset = 2;
        }

        std::cout << (k / n + (k % n == 0 ? 0 : offset)) << std::endl;
    }

    return 0;
}
#include <iostream>

int main() {
    int tests;
    std::cin >> tests;

    for (int i = 0; i < tests; ++i) {
        int rows;
        int cols;

        std::cin >> rows >> cols;

        if ((rows == 2 || rows == 3) && (cols == 2 || cols == 3))
            std::cout << "2 2" << std::endl;
        else
            std::cout << "1 1" << std::endl;
    }

    return 0;
}

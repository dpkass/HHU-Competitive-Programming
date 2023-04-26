#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    if (n == 1) {
        cout << (nums[0] != 1 ? "1" : "2");
        return 0;
    }

    sort(nums, nums + n);

    cout << "1 ";
    for (int i = 1; i < n - 1; ++i) {
        cout << nums[i - 1] << " ";
    }

    if (nums[n - 1] == 1)
        cout << "2" << endl;
    else
        cout << nums[n - 2] << endl;
}
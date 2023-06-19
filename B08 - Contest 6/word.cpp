#include <bits/stdc++.h>

using namespace std;

int main() {
    int upper, lower = upper = 0;

    string s;
    cin >> s;

    for (char c: s)
        if (islower(c)) lower++;
        else upper++;

    auto func = upper > lower ? ::toupper : ::tolower;

    for (char c: s)
        cout << (char) func(c);
    cout << endl;

    return 0;
}
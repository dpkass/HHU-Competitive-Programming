#include <iostream>

using namespace std;

int main() {
    string mirrorable("AHIMOTUVWXY");
    string str;
    cin >> str;

    string rev(str);
    reverse(rev.begin(), rev.end());

    for (int i = 0; i < str.length() / 2 + 1; ++i) {
        if (str[i] != rev[i] || mirrorable.find(str[i]) == string::npos) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
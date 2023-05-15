//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << endl
#define ll long long

int main() {
    Speed;

    string a, b;
    ll n, m;
    cin >> a >> b >> n >> m;

    // longer string
    if (a.length() + n > b.length() + m) {
        print("Arthur");
        return 0;
    } else if (a.length() + n < b.length() + m) {
        print("Nikita");
        return 0;
    }

    char ca;
    char cb;
    int i = 0;

    ll len = max(a.length(), b.length());
    while (i < len) {
        ca = i < a.length() ? a[i] : '9';
        cb = i < b.length() ? b[i] : '9';

        if (ca > cb) {
            print("Arthur");
            return 0;
        } else if (ca < cb) {
            print("Nikita");
            return 0;
        }
        i++;
    }

    print("Draw");

    return 0;
}
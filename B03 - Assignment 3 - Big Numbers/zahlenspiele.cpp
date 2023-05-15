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

#define check_win(ca, cb)   if (ca > cb) {\
                                print("Arthur");\
                                return 0;\
                            } else if (ca < cb) {\
                                print("Nikita");\
                                return 0;\
                            }

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

    ll len = min(a.length(), b.length());

    char ca;
    char cb;
    int i = 0;
    while (i < len) {
        ca = a[i];
        cb = b[i];

        check_win(ca, cb)
        i++;
    }

    len = max(a.length(), b.length());
    while (i < len) {
        ca = i < a.length() ? a[i] : '9';
        cb = i < b.length() ? b[i] : '9';

        check_win(ca, cb)
        i++;
    }

    print("Draw");

    return 0;
}
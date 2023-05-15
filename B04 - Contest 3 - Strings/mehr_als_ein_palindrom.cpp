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


void check_string(string s) {
    int other_c_counter = 0;

    char c = s[0];
    for (char &cs: s) {
        if (cs != c && other_c_counter++) {
            print("yes");
            return;
        }
    }
    print("nO");
}

int main() {
    Speed;

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;
        check_string(s);
    }

    return 0;
}

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

#define check   if (curr_len > max_len) {\
                    max_len = curr_len;\
                }

int main() {
    Speed;

    int n;
    string s;
    cin >> n >> s;

    int max_len = 0;
    int curr_len = 0;
    int par_words = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            check
            curr_len = 0;

            bool in_word = false;
            while (s[++i] != ')') {
                if (s[i] == '_' && in_word) {
                    par_words++;
                    in_word = false;
                } else if (s[i] != '_') {
                    in_word = true;
                }
            }
            if (in_word) par_words++;
        } else if (s[i] != '_') {
            curr_len++;
        } else {
            check
            curr_len = 0;
        }
    }
    check


    print(max_len << ' ' << par_words);

    return 0;
}
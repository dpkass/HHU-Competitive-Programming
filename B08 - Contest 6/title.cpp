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
#define half_incl(i) (i % 2 == 0) ? (i / 2) : (i / 2 + 1)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

char next_letter(bool letters[], int max) {
    for (int i = 0; i < max; ++i)
        if (!letters[i]) {
            letters[i] = true;
            return 'a' + i;
        }
    return 'a';
}

int main() {
    Speed;

    int k;
    cin >> k;

    string s;
    cin >> s;

    bool letters[26];
    memset(letters, true, 26);

    int last = s.size() - 1;
    int mid = half_incl(s.size());

    int count = 0;
    for (int i = 0; i < mid; ++i) {
        if (s[i] == '?') {
            if (s[last - i] == '?')
                count++;
            else {
                s[i] = s[last - i];
                letters[s[last - i] - 'a'] = false;
            }
        } else if (s[last - i] == '?') {
            s[last - i] = s[i];
            letters[s[i] - 'a'] = false;
        } else if (s[i] != s[last - i]) {
            print("IMPOSSIBLE");
            return 0;
        } else
            letters[s[i] - 'a'] = false;
    }


    queue<char> remaining;
    for (int i = 0; i < k; ++i)
        if (letters[i])
            remaining.push('a' + i);

    if (count < remaining.size()) {
        print("IMPOSSIBLE");
        return 0;
    }


    for (int i = 0; count > 0; ++i) {
        if (s[i] != '?') continue;

        if (count > remaining.size())
            s[i] = s[last - i] = 'a';
        else {
            s[i] = s[last - i] = remaining.front();
            remaining.pop();
        }
        count--;
    }

    print(s);

    return 0;
}
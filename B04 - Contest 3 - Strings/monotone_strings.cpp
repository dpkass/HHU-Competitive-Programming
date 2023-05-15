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

int find_following_start(string s, int start, int max, char c) {
    start++;
    while (s[start] != c && start < max) { start++; }
    return start;
}

int solve(string s, int n, int k, char c) {
    int max = 0;
    int cons = 0, seps = 0;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == c) cons++;  // is char
        else if (seps == k) {   // max sep reached and not char
            if (cons > max) max = cons;
            cons = 0;
            seps = 0;
            start = find_following_start(s, start, n, c);
            i = start;
        } else {                // max sep not reached and not char
            seps++;
            cons++;
        }
    }
    if (cons > max) max = cons;

    return max;
}

int main() {
    Speed;

    int n, k;
    string s;
    cin >> n >> k >> s;

    print(max(solve(s, n, k, 'a'), solve(s, n, k, 'b')));

    return 0;
}

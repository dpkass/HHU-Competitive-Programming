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
#define is_even(n) (n % 2 == 0) ? true : false

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int main() {
    Speed;

    int n;
    cin >> n;

    int flowers[n];
    for (int i = 0; i < n; ++i)
        cin >> flowers[i];

    int sum = accumulate(flowers, flowers + n, 0);
    if (!is_even(sum)) {
        print(sum);
        return 0;
    }

    sort(flowers, flowers + n);
    for (int i: flowers)
        if (!is_even(i)) {
            print(sum - i);
            return 0;
        }

    print(0);


    return 0;
}
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
#define print_col(a) for(auto item: a) cout << item << ' '

#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

bool leapyear(int curr) {
    return curr % 4 == 0 && (curr % 100 != 0 || curr % 400 == 0);
}

ll calc_days(ll x) {
    ll x_leapyears = x / 4 - x / 100 + x / 400;
    return x * 365 + x_leapyears + 1;
}

void solve() {
    ll x;
    cin >> x;

    ll jan_1_x_days = calc_days(x);
    ll x_first_day = jan_1_x_days % 7;

    int curr = x;
    int curr_days = calc_days(curr);

    bool x_is_leap = leapyear(x);

    while (true) {
        curr++;
        curr_days += 365;
        if (leapyear(curr)) curr_days++;

        if (curr_days % 7 == x_first_day && x_is_leap == leapyear(curr)) {
            print(curr);
            return;
        }
    }
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
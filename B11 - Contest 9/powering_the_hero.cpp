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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;
typedef multiset<int> msi;
typedef multiset<pi> msii;

//#define int ll

void solve() {
    int n;
    cin >> n;

    ll sum = 0, x;
    priority_queue<ll> cards;
    while (n--) {
        cin >> x;
        if (x == 0 && !cards.empty()) {
            sum += cards.top();
            cards.pop();
        }

        cards.push(x);
    }

    print(sum);
}

signed main() {
    Speed;

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
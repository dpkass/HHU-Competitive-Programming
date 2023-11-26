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

//#define int ll

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef set<int> si;

template <typename Iterator>
int maxProduct(Iterator start, Iterator end) {
    int max_ = *start;
    int prod = 1;
    while (start != end) {
        prod *= *start;
        max_ = max(max_, prod);
        if (*start == 0) prod = 1;
        start++;
    }
    return max_;
}

int maxProduct(vector<int> &nums) {
    return max(maxProduct(nums.begin(), nums.end()), maxProduct(nums.rbegin(), nums.rend()));
}

void solve() {
    int n;
    cin >> n;

    vi vals(n);
    while (n--) cin >> vals[n];

    print(maxProduct(vals));
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    solve();

    return 0;
}
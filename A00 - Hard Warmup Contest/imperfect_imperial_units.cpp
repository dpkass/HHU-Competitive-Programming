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
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;
typedef multiset<int> msi;
typedef multiset<pi> msii;

typedef struct conversion {
    string to;
    ld val;
} conversion;

typedef vector<conversion> vc;

ld find_conv_rate(map<string, vc> &conv_map, string &to, set<string> &seen, vc &convs) {
    for (;;) {
        for (conversion &conv: convs)
            if (conv.to == to)
                return conv.val;

        for (conversion &conv: convs) {
            if (seen.count(conv.to)) continue;
            seen.emplace(conv.to);

            ld conv_rate = find_conv_rate(conv_map, to, seen, conv_map[conv.to]);
            if (conv_rate < 0) continue;

            return conv.val * conv_rate;
        }

        return -1;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    map<string, vc> conv_map;
    while (n--) {
        string from, to, _;
        ld val_from, val_to;

        cin >> val_from >> from >> _ >> val_to >> to;

        conv_map[from].push_back({to, val_to / val_from});
        conv_map[to].push_back({from, val_from / val_to});
    }

    while (q--) {
        string from, to, _;
        ld val;

        cin >> val >> from >> _ >> to;

        set<string> seen;

        vc current = conv_map[from];
        ld conv_rate = find_conv_rate(conv_map, to, seen, current);

        if (conv_rate == -1) print("impossible");
        else
            print(val * conv_rate);
    }
}

signed main() {
    Speed;

    cout.precision(20);

    solve();

    return 0;
}
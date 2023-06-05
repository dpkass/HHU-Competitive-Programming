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
#define ll unsigned long long


ll get_sum(vector<int> positions) {
    sort(positions.begin(), positions.end());

    ll res = 0;
    // die kumulierte summe aller distanzen vom ersten
    ll sum = accumulate(positions.begin(), positions.end(), 0);
    ll prefix_sum = 0;
    for (size_t i = 0; i < positions.size(); ++i) {
        // entferne die distanz vom iten und addiere die distanz * anzahl der restlichen
        sum -= positions[i];
//        res += (i + 1) * positions[i] - sum;
        res += (sum - prefix_sum) - (positions.size() - 1 - i) * positions[i];
        prefix_sum += positions[i];
    }

    return res;
}

int solve() {
    Speed;

    int n, m;
    cin >> n >> m;

    map<int, vector<int>> color_to_x;
    map<int, vector<int>> color_to_y;

    int x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> x;
            color_to_x[x].push_back(j);
            color_to_y[x].push_back(i);
        }
    }

    ll sum = 0;
    for (auto &[_, positions]: color_to_x) sum += get_sum(positions);
    for (auto &[_, positions]: color_to_y) sum += get_sum(positions);

    print(sum);

    return 0;
}
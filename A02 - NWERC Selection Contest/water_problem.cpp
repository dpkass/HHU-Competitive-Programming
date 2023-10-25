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

typedef vector<vi> vvi;

#define left col-1
#define right col+1
#define up row-1
#define down row+1

ll rows, cols;

ll search_lake(vvi &map, ll row, ll col) {
    ll sum = map[row][col];
    map[row][col] = 0;
    if (left >= 0 && map[row][left] > 0)sum += search_lake(map, row, left);
    if (right < cols && map[row][right] > 0)sum += search_lake(map, row, right);
    if (up >= 0 && map[up][col] > 0)sum += search_lake(map, up, col);
    if (down < rows && map[down][col] > 0)sum += search_lake(map, down, col);

    return sum;
}

void solve() {
    cin >> rows >> cols;

    vvi map;
    for (int i = 0; i < rows; ++i) {
        vi temp;
        for (int j = 0, x; j < cols; ++j)
            cin >> x, temp.push_back(x);
        map.push_back(temp);
    }

    ll highest = 0;
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            if (map[i][j] > 0)
                highest = max(highest, search_lake(map, i, j));
    print(highest);
}

signed main() {
    Speed;

#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
#endif

    ll t;
    cin >> t;
    while (t--) solve();

    return 0;
}
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
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef set<int> si;
typedef set<pi> sii;

int n, m;
vs field;
vvi regions;
vvi regionids;

void find_region_coords(int i, int j, vii &coords) {
    if (field[i][j] != '.') return;

    coords.emplace_back(i, j);
    field[i][j] = 'o';

    if (i > 0) find_region_coords(i - 1, j, coords);
    if (i < n - 1) find_region_coords(i + 1, j, coords);
    if (j > 0) find_region_coords(i, j - 1, coords);
    if (j < m - 1) find_region_coords(i, j + 1, coords);
}

void build_regions() {
    int counter = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            counter++;
            vii coords;
            find_region_coords(i, j, coords);

            int regionSize = coords.size();
            for (const auto [x, y]: coords) {
                regions[x][y] = regionSize;
                regionids[x][y] = counter;
            }
        }
}

void solve() {
    cin >> n >> m;
    regions.assign(n, vi(m));
    regionids.assign(n, vi(m));

    field.assign(n, "");
    for (int i = 0; i < n; ++i)
        cin >> field[i];

    build_regions();


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (field[i][j] == 'o') cout << '.';
            else {
                int sum = 1;
                si ids;
                if (i > 0 && field[i - 1][j] == 'o') {
                    sum += regions[i - 1][j];
                    ids.insert(regionids[i - 1][j]);
                }
                if (i < n - 1 && field[i + 1][j] == 'o' && !ids.count(regionids[i + 1][j])) {
                    sum += regions[i + 1][j];
                    ids.insert(regionids[i + 1][j]);
                }
                if (j > 0 && field[i][j - 1] == 'o' && !ids.count(regionids[i][j - 1])) {
                    sum += regions[i][j - 1];
                    ids.insert(regionids[i][j - 1]);
                }
                if (j < m - 1 && field[i][j + 1] == 'o' && !ids.count(regionids[i][j + 1])) {
                    sum += regions[i][j + 1];
                    ids.insert(regionids[i][j + 1]);
                }

                cout << sum % 10;
            }
        }
        cout << endl;
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
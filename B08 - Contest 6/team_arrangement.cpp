//
// Created by dpkass
//

#include <bits/stdc++.h>

using namespace std;

#define Speed                   \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0)
#define print(i) cout << i << ' '

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

bool contains(vi &v, int i) {
    for (int mem: v)
        if (mem == i)
            return true;
    return false;
}

int main() {
    Speed;

    int n;
    cin >> n;

    n *= 3;

    int rank[n + 1];
    for (int i = 0, x; i < n; ++i)
        cin >> x, rank[x] = i;


    int teams[n];
    for (int i = 0; i < n; ++i)
        cin >> teams[i];

    int k;
    cin >> k;

    int idx = 0;
    for (; idx < n; ++idx)
        if (teams[idx] == k)
            break;

    int end = idx / 3 * 3 + 3; // last of left side

    vi k_team(teams + end - 3, teams + end);

    for (int i: k_team)
        if (rank[i] < rank[k]) { // prio list unknown
            for (int j = 1; j <= n; ++j)
                if (j != k)
                    print(j);
            return 0;
        }



    // l = teams[..., end - 1], r = [end, ...]
    // l contains the team of k and above (left side of prio list)
    // r contains the rest (right side of prio list)
    // if prio list unknown print 1,...,n (lexicogrphically smallest)
    vi l(teams, teams + end);
    vi r(teams + end, teams + n);

    l.erase(l.begin() + idx);

    sort(l.begin(), l.end());

    // any values in l greater than team members should be moved to r (lexicogrphically smallest)
    for (int i = l.size() - 1; i > 0; --i) {
        if (contains(k_team, l[i])) break;
        r.push_back(l[i]);
        l.pop_back();
    }

    sort(r.begin(), r.end());

    for (const auto i: l) print(i);
    for (const auto i: r) print(i);

    return 0;
}
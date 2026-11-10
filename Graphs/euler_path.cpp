#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))

vector<vector<pair<int, int>>> g;
vector<bool> vis;
vector<int> first;
vector<pair<int, int>> path;

void euler(int v) {
  while (first[v] < sz(g[v])) {
    pair<int, int> p = g[v][first[v]];
    first[v]++;
    int i = p.first;
    int u = p.second;
    if (not vis[i]) {
      vis[i] = true;
      euler(u);
      path.push_back(make_pair(u, v));
    }
  }
}

int solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n + 1);
  vis.resize(m + 2, false);
  first.resize(n + 1);
  int x = -1, y = -1;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(make_pair(i, v));
    g[v].push_back(make_pair(i, u));
  }
  for (int i = 0; i < n; i++) {
    if (sz(g[i]) % 2 == 1) {
      if (x == -1) {
        x = i;
        cout << x << endl;
      } else {
        y = i;
        cout << y << endl;
      }
    }
  }
  int k = n;
  g[k].push_back(make_pair(m, x));
  g[x].push_back(make_pair(m, k));

  g[k].push_back(make_pair(m + 1, y));
  g[y].push_back(make_pair(m + 1, k));
  euler(k);
  cout << "----------" << endl;

  for (int i = 1; i < sz(path) - 1; i++)
    cout << path[i].first + 1 << ' ' << path[i].second + 1 << endl;

  return 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}
/*
5 6
1 2
2 5
1 5
3 5
3 4
4 5
*/
/*
6 6
1 2
2 3
3 4
3 5
3 6
5 6
*/

#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))

vector<pair<int, int>> path;
vector<vector<pair<int, int>>> g;
vector<int> first;
vector<bool> vis;

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
  g.resize(n);
  first.resize(n);
  vis.resize(m, false);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(make_pair(i, v));
    g[v].push_back(make_pair(i, u));
  }
  euler(0);
  cout << "-------" << endl;
  for (int i = 0; i < sz(path); i++)
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
6 7
1 2
2 3
2 4
3 4
3 5
4 5
5 6
*/

#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))

vector<int> up;
vector<int> in;
vector<bool> mark;
vector<vector<int>> g;
int t = 0;
vector<pair<int, int>> bridges;

void dfs(int v, int p) {
  up[v] = in[v] = t++;
  mark[v] = true;
  for (int u : g[v]) {
    if (u == p) {
      continue;
    }
    if (mark[u]) {
      up[v] = min(in[u], up[v]);
    } else {
      dfs(u, v);
      up[v] = min(up[u], up[v]);
    }
  }
  if (up[v] >= in[v] and p != -1) {
    bridges.push_back(make_pair(min(v, p) + 1, max(v, p) + 1));
  }
}

void find_bridges(int n) {
  t = 0;
  for (int i = 0; i < n; i++) {
    if (not mark[i]) {
      dfs(i, -1);
    }
  }
}

int solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  mark.resize(n, false);
  in.resize(n);
  up.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  find_bridges(n);
  for (int i = 0; i < sz(bridges); i++)
    cout << bridges[i].first << ' ' << bridges[i].second << endl;
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

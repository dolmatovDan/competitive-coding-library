#include <bits/stdc++.h>
using namespace std;

vector<int> colors;
vector<vector<int>> g;
bool ans = true;

void dfs(int v, int color) {
  colors[v] = color;
  for (int u : g[v]) {
    if (colors[u] == colors[v]) {
      ans = false;
      return;
    }
    if (colors[u] == -1) {
      dfs(u, 1 - colors[v]);
    }
  }
}

int solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  colors.resize(n, -1);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  for (int i = 0; i < n; i++) {
    if (colors[i] == -1) {
      dfs(i, 0);
    }
  }
  if (ans) {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
      cout << colors[i] + 1 << ' ';
  } else {
    cout << "NO" << endl;
  }
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

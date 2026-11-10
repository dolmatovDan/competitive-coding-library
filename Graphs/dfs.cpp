#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;

vector<vector<int>> g;
vector<int> colors;

void dfs(int v, int color) {
  colors[v] = color;
  for (int u : g[v]) {
    if (colors[u] == 0) {
      dfs(u, color);
    }
  }
}

int solve() {
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  colors.resize(n);
  int c = 1;
  for (int i = 0; i < n; i++) {
    if (colors[i] == 0) {
      dfs(i, c);
      c++;
    }
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

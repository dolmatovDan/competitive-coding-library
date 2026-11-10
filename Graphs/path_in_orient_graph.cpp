#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()

vector<int> used;
vector<vector<int>> g;
vector<int> path;
vector<int> ind;
vector<int> ans;

void copyVec(vector<int> &a, vector<int> &b, int x, int y) {
  for (int i = x; i < y; i++) {
    b.push_back(a[i]);
  }
}

bool dfs(int v) {
  used[v] = 1;
  ind[v] = path.size();
  path.push_back(v);
  for (int u : g[v]) {
    if (used[u] == 1) {
      copyVec(path, ans, ind[u], ind[v] + 1);
      return true;
    }
    if (used[u] == 0) {
      if (dfs(u)) {
        return true;
      }
    }
  }
  used[v] = 2;
  return false;
}

int solve() {
  int n, m;
  cin >> n >> m;
  used.resize(n, 0);
  ind.resize(n);
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> v >> u;
    u--;
    v--;
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (dfs(i)) {
      cout << "YES" << endl;
      for (int j = 0; j < sz(ans); j++)
        cout << ans[j] + 1 << ' ';
      return 0;
    }
  }
  cout << "NO" << endl;
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

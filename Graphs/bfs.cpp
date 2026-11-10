#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> g;

int solve() {
  int n, s, f;
  cin >> n >> s >> f;
  s--;
  f--;
  g.resize(n);
  int x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> x;
      if (x == 1) {
        g[i].push_back(j);
      }
    }
  }
  vector<int> dist(n, -1);
  deque<int> q;
  q.push_back(s);
  dist[s] = 0;
  while (not q.empty()) {
    int v = q[0];
    q.pop_front();
    for (int u : g[v]) {
      if (dist[u] == -1) {
        dist[u] = dist[v] + 1;
        q.push_back(u);
      }
    }
  }
  if (dist[f] == -1)
    cout << 0 << endl;
  else
    cout << dist[f] << endl;
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

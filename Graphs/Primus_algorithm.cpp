#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Primus {
  vector<vector<pair<int, int>>> g;
  int n;
  ll res;
  const ll INF = 2e18;
  void init(vector<vector<pair<int, int>>> _g) {
    n = (int)_g.size();
    g.resize(n);
    vector<int> back(n, INF), vis(n);
    res = 0;
    for (int i = 0; i < n; ++i) {
      ll mn = INF;
      int v = -1;
      for (int u = 0; u < n; ++u) {
        if (back[u] <= mn && !vis[u]) {
          v = u;
          mn = back[u];
        }
      }
      if (v == -1)
        break;
      vis[v] = 1;
      if (mn != INF) {
        res += INF;
      }
      for (auto [u, cost] : g[v]) {
        if (!vis[u]) {
          back[u] = min(back[u], cost);
        }
      }
    }
  }
  ll get() { return res; }
};

signed main() {}

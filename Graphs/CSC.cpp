#include <bits/stdc++.h>
using namespace std;

struct CSC {
  vector<vector<int>> g, g_rev;
  vector<int> comp, vis, topsort;
  int cnt_components;
  void dfs1(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
      if (!vis[u]) {
        dfs1(u);
      }
    }
    topsort.push_back(v);
  }
  void dfs2(int v) {
    comp[v] = cnt_components;
    for (int u : g_rev[v]) {
      if (comp[u] == 0) {
        dfs2(u);
      }
    }
  }
  void init(vector<vector<int>> _g) {
    g.resize((int)_g.size());
    g_rev.resize((int)_g.size());
    cnt_components = 1;
    for (int v = 0; v < (int)_g.size(); ++v) {
      for (int u : _g[v]) {
        g[v].push_back(u);
        g_rev[u].push_back(v);
      }
    }
    for (int v = 0; v < (int)_g.size(); ++v) {
      if (!vis[v]) {
        dfs1(v);
      }
    }
    reverse(topsort.begin(), topsort.end());
    for (int u : topsort) {
      if (!comp[u]) {
        dfs2(u);
        cnt_components++;
      }
    }
  }
  vector<int> get_components() { return comp; }
};

signed main() {}

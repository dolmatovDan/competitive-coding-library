#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)(a).size())
template <class T> struct SparseTable {
  const int LOG = 22;
  int n;
  vector<vector<T>> m;
  T query_op(T a, T b) { return min(a, b); }
  void init(vector<T> a) {
    n = (int)a.size();
    m.resize(LOG);
    m[0] = a;
    for (int d = 1; d < LOG; ++d) {
      for (int i = 0; i + (1 << d) <= n; ++i) {
        m[d].push_back(query_op(m[d - 1][i], m[d - 1][i + (1 << (d - 1))]));
      }
    }
  }
  T query(int l, int r) { // [l; r)
    int d = 31 - __builtin_clz(r - l);
    return query_op(m[d][l], m[d][r - (1 << d)]);
  }
};

struct LCA_Sparse_Table {
  vector<int> dist, pos;
  vector<vector<int>> g;
  vector<pair<int, int>> a;
  SparseTable<pair<int, int>> st;
  int n;

  void dfs(int v, int p = -1) {
    pos[v] = sz(a);
    a.emplace_back(dist[v], v);
    for (int u : g[v]) {
      if (u != p) {
        dfs(u, v);
        a.emplace_back(dist[v], v);
      }
    }
  }

  void init(vector<vector<int>> _g) {
    g = _g;
    n = sz(g);
    dist.assign(n, -1);
    pos.assign(n, -1);
    dist[0] = 0;
    deque<int> dq = {0};
    while (!dq.empty()) {
      int v = dq[0];
      dq.pop_front();
      for (int u : g[v]) {
        if (dist[u] == -1) {
          dist[u] = dist[v] + 1;
          dq.push_back(u);
        }
      }
    }
    dfs(0, -1);
    st.init(a);
  }
  int get(int u, int v) {
    int l = pos[u], r = pos[v];
    if (l > r)
      swap(l, r);
    return st.query(l, r + 1).second;
  }
};

signed main() { return 0; }

#include <bits/stdc++.h>
using namespace std;

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

signed main() {}

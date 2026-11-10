#include <bits/stdc++.h>
using namespace std;

template <typename T, typename Ans> struct disjointSparseTable {
  int n, LOG, size;
  const Ans NEUTRAL = {2e9, -1};
  vector<vector<Ans>> st;
  Ans query_op(Ans a, Ans b) {
    if (a.first != b.first) {
      return (a.first < b.first ? a : b);
    }
    return make_pair(a.first, a.second + b.second);
  }
  void build(vector<T> arr) {
    for (int k = 0; k < LOG; ++k) {
      int len = (1 << k);
      for (int center = len; center < size; center += 2 * len) {
        Ans pref = NEUTRAL;
        for (int i = center; i < center + len; ++i) {
          st[k][i] = pref;
          pref = query_op({arr[i], 1}, pref);
        }
        for (int i = center - 1; i >= center - len; --i) {
          st[k][i] = query_op(st[k][i + 1], {arr[i], 1});
        }
      }
    }
  }
  void init(vector<T> arr) {
    n = arr.size();
    size = 1;
    LOG = 0;
    while (size <= n) {
      size *= 2;
      LOG++;
    }
    arr.resize(size, -1);
    st.assign(LOG, vector<Ans>(size));
    build(arr);
  }
  Ans query(int l, int r) { // [l; r)
    int curH = 31 - __builtin_clz(l ^ r);
    return query_op(st[curH][l], st[curH][r]);
  }
};

signed main() {}

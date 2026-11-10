#include <bits/stdc++.h>
using namespace std;
#define len(a) ((int)(a.size()))

typedef long long ll;
typedef long double ld;

struct SegTree {
  struct node {
    ll set, min;
  };
  vector<node> tree;
  int size, n;
  ll NO_OP = LLONG_MIN;
  ll NEUTRAL = LLONG_MAX;
  void init(int _n) {
    n = _n;
    size = 1;
    while (size < n)
      size *= 2;
    tree.assign(size * 2, {0, 0});
  }
  ll op_modify(ll a, ll b, ll len) {
    if (b == NO_OP)
      return a;
    return b;
  }
  ll op_sum(ll a, ll b) { return min(a, b); }
  void propagate(int x, int lx, int rx) {
    if (tree[x].set == NO_OP || rx - lx == 1)
      return;
    int m = (lx + rx) / 2;
    tree[2 * x + 1].set = op_modify(tree[2 * x + 1].set, tree[x].set, 1);
    tree[2 * x + 1].min = op_modify(tree[2 * x + 1].min, tree[x].set, m - lx);
    tree[2 * x + 2].set = op_modify(tree[2 * x + 2].set, tree[x].set, 1);
    tree[2 * x + 2].min = op_modify(tree[2 * x + 2].min, tree[x].set, rx - m);
    tree[x].set = NO_OP;
  }
  void mult(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r)
      return;
    if (lx >= l && rx <= r) {
      tree[x].set = op_modify(tree[x].set, v, 1);
      tree[x].min = op_modify(tree[x].min, v, rx - lx);
      return;
    }
    int m = (lx + rx) / 2;
    mult(l, r, v, x * 2 + 1, lx, m);
    mult(l, r, v, x * 2 + 2, m, rx);
    tree[x].min = op_sum(tree[x * 2 + 1].min, tree[x * 2 + 2].min);
  }
  void mult(int l, int r, int v) { mult(l, r, v, 0, 0, size); }
  ll sum(int l, int r, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx || lx >= r)
      return NEUTRAL;
    if (lx >= l && rx <= r)
      return tree[x].min;
    int m = (lx + rx) / 2;
    ll m1 = sum(l, r, x * 2 + 1, lx, m);
    ll m2 = sum(l, r, x * 2 + 2, m, rx);
    return op_sum(m1, m2);
  }
  ll sum(int l, int r) { return sum(l, r, 0, 0, size); }
};

void solve() {
  int n, m;
  cin >> n >> m;
  SegTree st;
  st.init(n);
  while (m--) {
    int com;
    cin >> com;
    if (com == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.mult(l, r, v);
    } else {
      int l, r;
      cin >> l >> r;
      cout << st.sum(l, r) << '\n';
    }
  }
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  //    cin >> tt;
  while (tt--) {
    solve();
#ifndef ONLINE_JUDGE
    cout << "_______________________\n";
#endif
  }
  return 0;
}

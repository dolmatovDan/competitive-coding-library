#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segtree {
  vector<ll> tree;
  int NO_OPER = 0;
  int size = 1;
  void init(int n) {
    while (size < n)
      size *= 2;
    tree.assign(size * 2, 0);
  }
  void propagate(int x, int lx, int rx) {
    if (tree[x] == NO_OPER or rx - lx == 1)
      return;
    tree[x * 2 + 1] += tree[x];
    tree[x * 2 + 2] += tree[x];
    tree[x] = NO_OPER;
  }
  void modify(int l, int r, int v, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (l >= rx or lx >= r) {
      return;
    }
    if (lx >= l && rx <= r) {
      tree[x] += v;
      return;
    }
    int m = (lx + rx) / 2;
    modify(l, r, v, x * 2 + 1, lx, m);
    modify(l, r, v, x * 2 + 2, m, rx);
  }
  void modify(int l, int r, int v) { modify(l, r, v, 0, 0, size); }
  ll get(int i, int x, int lx, int rx) {
    propagate(x, lx, rx);
    if (rx - lx == 1) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      return get(i, x * 2 + 1, lx, m);
    } else {
      return get(i, x * 2 + 2, m, rx);
    }
  }
  ll get(int i) { return get(i, 0, 0, size); }
  void print() {
    for (auto x : tree)
      cout << x << ' ';
    cout << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  segtree st;
  st.init(n);
  int com;
  while (m--) {
    cin >> com;
    if (com == 1) {
      int l, r, v;
      cin >> l >> r >> v;
      st.modify(l, r, v);
      //            st.print();
    } else {
      int i;
      cin >> i;
      cout << st.get(i) << '\n';
    }
  }
}

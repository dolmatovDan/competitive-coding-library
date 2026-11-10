#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct SegTree {
  vector<ll> tree;
  int size = 1;
  void init(int n) {
    size = 1;
    while (size < n)
      size *= 2;
    tree.assign(2 * size, 0);
  }
  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < a.size())
        tree[x] = a[lx];
      return;
    }
    int m = (lx + rx) / 2;
    build(a, x * 2 + 1, lx, m);
    build(a, x * 2 + 2, m, rx);
    tree[x] = tree[x * 2 + 1] + tree[x * 2 + 2];
  }

  void build(vector<int> &a) {
    init(a.size());
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m)
      set(i, v, x * 2 + 1, lx, m);
    else
      set(i, v, x * 2 + 2, m, rx);
    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
  }
  void set(int i, int v) { set(i, v, 0, 0, size); }
  ll sum(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) {
      return 0;
    }
    if (lx >= l && rx <= r) {
      return tree[x];
    }
    int m = (lx + rx) / 2;
    ll s1 = sum(l, r, x * 2 + 1, lx, m);
    ll s2 = sum(l, r, x * 2 + 2, m, rx);
    return s1 + s2;
  }
  ll sum(int l, int r) { return sum(l, r, 0, 0, size); }

  void print() {
    for (int i = 0; i < tree.size(); ++i)
      cout << tree[i] << ' ';
    cout << '\n';
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  SegTree st;

  st.build(a);
  while (m--) {
    int com;
    cin >> com;
    if (com == 1) {
      int i, v;
      cin >> i >> v;
      st.set(i, v);
    } else {
      int l, r;
      cin >> l >> r;
      ll res = st.sum(l, r);
      cout << res << '\n';
    }
  }

  return 0;
}

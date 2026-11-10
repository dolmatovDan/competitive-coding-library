#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)((a).size())

struct PersSegTree {
  struct Node {
    int sum, left, right;
    Node() {
      sum = 0;
      left = right = -1;
    }
    Node(int _sum, int _left, int _right) {
      left = _left;
      sum = _sum;
      right = _right;
    }
  };
  vector<Node> tree;
  vector<int> start;
  int n, cur_start;

  int build(int lx, int rx) {
    int e = sz(tree);
    tree.push_back({});
    if (rx - lx == 1) {
      tree[e] = Node(0, -1, -1);
      return e;
    }
    int m = (lx + rx) / 2;
    int w = build(lx, m);
    tree[e].left = w;
    w = build(m, rx);
    tree[e].right = w;
    tree[e].sum = 0;
    return e;
  }

  void init(int k) {
    n = k;
    start.push_back(0);
    cur_start = 0;
    build(0, n);
  }

  int add(int pos, int val, int x, int lx, int rx) {
    int e = sz(tree);
    tree.push_back({});
    if (rx - lx == 1) {
      tree[e] = tree[x];
      tree[e].sum += val;
      return e;
    }
    tree[e] = tree[x];
    int m = (lx + rx) / 2;
    if (pos < m) {
      int w = add(pos, val, tree[x].left, lx, m);
      tree[e].left = w;
    } else {
      int w = add(pos, val, tree[x].right, m, rx);
      tree[e].right = w;
    }
    tree[e].sum = tree[tree[e].left].sum + tree[tree[e].right].sum;
    return e;
  }

  void add(int pos, int val) {
    int s = add(pos, val, cur_start, 0, n);
    start.push_back(s);
    cur_start = s;
  }

  void change_version(int k) { cur_start = start[k]; }

  int get(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r)
      return 0;
    if (l <= lx && rx <= r)
      return tree[x].sum;
    int m = (lx + rx) / 2;
    return get(l, r, tree[x].left, lx, m) + get(l, r, tree[x].right, m, rx);
  }

  int get(int l, int r) { return get(l, r, cur_start, 0, n); }

  int go(int k, int x1, int x2, int lx, int rx) {
    if (rx - lx == 1)
      return lx;
    int cur_left = abs(tree[tree[x1].left].sum - tree[tree[x2].left].sum);

    int m = (lx + rx) / 2;
    if (cur_left >= k) {
      return go(k, tree[x1].left, tree[x2].left, lx, m);
    }
    return go(k - cur_left, tree[x1].right, tree[x2].right, m, rx);
  }

  int go(int k, int x1, int x2) { return go(k, start[x1], start[x2], 0, n); }

  void print() {
    for (int i = 0; i < n; ++i) {
      cout << get(i, i + 1) << " ";
    }
    cout << '\n';
  }
};

signed main() {}

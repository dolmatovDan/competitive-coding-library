// Здесь может быть лажа
#include <bits/stdc++.h>
using namespace std;

const long long INF = 2e15;

struct Line {
  long long k, b;
  long long get(int x) { return k * x + b; }
  Line(long long _k, long long _b) {
    k = _k;
    b = _b;
  }
};

struct LiChaoTree {
  vector<Line> tree;
  int n, size;
  Line NEUTRAL = Line(0, INF);
  void init(int _n) {
    n = _n;
    size = 1;
    while (size < n)
      size *= 2;
    tree.resize(size * 2, NEUTRAL);
    size = n;
  }
  void add(Line L, int x, int lx, int rx) {
    int m = (rx + lx) / 2;
    bool dominatedLeft = L.get(lx) < tree[x].get(lx);
    bool dominatedMid = L.get(m) < tree[x].get(m);
    if (dominatedMid) {
      swap(L, tree[x]);
    }
    if (rx - lx == 1)
      return;
    if (dominatedMid == dominatedLeft) {
      add(L, x * 2 + 2, m, rx);
    } else {
      add(L, x * 2 + 1, lx, m);
    }
  }
  void add(Line L) { add(L, 0, 0, size); }
  long long get(int pos, int x, int lx, int rx) {
    if (rx - lx == 1) {
      return tree[x].get(pos);
    }
    int m = (lx + rx) / 2;
    long long res1 = get(pos, x * 2 + 1, lx, m);
    long long res2 = get(pos, x * 2 + 2, m, rx);
    return min({res1, res2, tree[x].get(pos)});
  }
  long long get(int pos) { return get(pos, 0, 0, size); }
};

signed main() {}

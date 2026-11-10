#include <bits/stdc++.h>
using namespace std;

struct DSU {
  int size;
  vector<int> p, r;
  void init(int n) {
    size = n;
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    r.assign(n, 1);
  }
  int get(int a) {
    if (a == p[a]) {
      return a;
    }
    p[a] = get(p[a]);
    return p[a];
  }

  void join(int _a, int _b) {
    int a = get(_a);
    int b = get(_b);
    if (r[a] > r[b]) {
      swap(a, b);
    }
    p[a] = b;
    if (r[a] == r[b]) {
      r[b]++;
    }
  }
};

signed main() { return 0; }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Fenvick {
  int n;
  vector<ll> f;
  void init(vector<int> &a) {
    n = (int)a.size();
    f.resize(n);
    f[0] = a[0];
    for (int i = 1; i < n; i++)
      f[i] = f[i - 1] + a[i];
    for (int i = n - 1; i > 0; i--) {
      int lw = (i & (i + 1)) - 1;
      if (lw >= 0)
        f[i] -= f[lw];
    }
  }
  ll sum(int r) {
    int x = r - 1;
    ll res = 0;
    while (x >= 0) {
      res += f[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
  ll sum(int l, int r) { return sum(r) - sum(l); }
  void inc(int pos, int v) {
    int j = pos;
    while (j < n) {
      f[j] += v;
      j = j | (j + 1);
    }
  }
};

signed main() {}

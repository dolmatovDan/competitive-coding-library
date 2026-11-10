// Здесь может быть лажа
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

struct line {
  ld k;
  ld b;
  ld operator()(ld x) { return k * x + b; }
};
vector<line> sortedLines(vector<line> k) {
  int n = k.size();
  sort(k.begin(), k.end(), [](line a, line b) {
    if (abs(a.k - b.k) > 1e-12)
      return a.k > b.k;
    return a.b < b.b;
  });
  vector<line> res = {k[0]};
  for (int i = 0; i < n - 1; ++i) {
    if (k[i + 1].k != k[i].k) {
      res.push_back(k[i + 1]);
    }
  }
  return res;
}
struct CHT {
  const ld inf = 1e15;
  ld cross(line a, line b) { return (a.b - b.b) / (b.k - a.k); }
  struct seg {
    ld x1, x2;
    seg(ld _x1, ld _x2) {
      x1 = _x1;
      x2 = _x2;
    }
  };
  vector<pair<line, seg>> st;
  void init(vector<line> k) {
    st.emplace_back(k[0], seg(-inf, inf));
    for (int i = 1; i < (int)k.size(); ++i) {
      while ((int)st.size()) {
        ld xx = cross(st.back().first, k[i]);
        if (xx < st.back().second.x1) {
          st.pop_back();
          continue;
        }
        st.back().second.x2 = xx;
        st.emplace_back(k[i], seg(xx, inf));
        break;
      }
    }
  }
  ld get(ld x) {
    int l = 0;
    int r = (int)st.size();
    while (r > l + 1) {
      int mid = (r + l) / 2;
      (st[mid].second.x1 <= x ? l : r) = mid;
    }
    return st[l].first(x);
  }
};

int main() {
  int n;
  cout.precision(20);
  cin >> n;
  vector<line> ln(n);
  for (line &x : ln)
    cin >> x.k >> x.b;
  ln = sortedLines(ln);
  CHT st;
  st.init(ln);
  int q;
  cin >> q;
  while (q--) {
    ld x;
    cin >> x;
    cout << st.get(x) << endl;
  }
  return 0;
}

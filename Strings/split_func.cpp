#include <bits/stdc++.h>
using namespace std;
#define len(a) (int)(a.size())

vector<string> split(string s, string sep = " ") {
  vector<string> res;
  string term = "#";
  s = sep + term + s;
  int n = len(s);
  vector<int> z(n);
  z[0] = 0;
  int l = 0, r = 0;
  for (int i = 1; i < n; ++i) {
    if (i <= r)
      z[i] = min(z[i - l], r - i + 1);
    while (i + z[i] < n and s[z[i]] == s[i + z[i]])
      z[i]++;
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  string cur = "";
  for (int i = len(term) + len(sep); i < len(s); ++i) {
    if ((z[i] == len(sep) and len(cur))) {
      res.push_back(cur);
      cur = "";
    } else if (z[i] != len(sep)) {
      cur += s[i];
    }
    if (z[i] != len(sep) and i == len(s) - 1) {
      res.push_back(cur);
    }
    if (z[i] == len(sep))
      i += z[i] - 1;
  }
  return res;
}

signed main() { return 0; }

#include <bits/stdc++.h>
using namespace std;

vector<int> pref_func(string s) {
  int n = (int)s.size();
  vector<int> p(n);
  for (int i = 1; i < n; ++i) {
    int j = p[i - 1];
    while (j > 0 and s[i] != s[j])
      j = p[j - 1];
    if (s[i] == s[j])
      j++;
    p[i] = j;
  }
  return p;
}

signed main() { return 0; }

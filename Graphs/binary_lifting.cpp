#include <bits/stdc++.h>
using namespace std;
// root in zero vertex
vector<vector<int>> bin_lift(vector<int> parent) {
  int n = (int)parent.size();
  int LOG = 0;
  int tmp = 1;
  while (tmp < n) {
    tmp *= 2;
    LOG++;
  }
  vector<vector<int>> jmp(n, vector<int>(LOG + 1));
  parent[0] = 0;
  for (int v = 0; v < n; ++v) {
    jmp[v][0] = parent[v];
    for (int k = 1; k <= LOG; ++k) {
      jmp[v][k] = jmp[jmp[v][k - 1]][k - 1];
    }
  }
  return jmp;
}

signed main() { return 0; }

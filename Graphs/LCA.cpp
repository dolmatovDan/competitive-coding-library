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
  parent[0] = 0;
  vector<vector<int>> jmp(n, vector<int>(LOG + 1));
  for (int v = 0; v < n; ++v) {
    jmp[v][0] = parent[v];
    for (int k = 1; k <= LOG; ++k) {
      jmp[v][k] = jmp[jmp[v][k - 1]][k - 1];
    }
  }
  return jmp;
}

int LCA(int u, int v, vector<int> parent, vector<int> d) {
  if (d[u] < d[v])
    swap(u, v);
  int n = (int)parent.size();
  int LOG = 0;
  int tmp = 1;
  while (tmp < n) {
    tmp *= 2;
    LOG++;
  }
  vector<vector<int>> jmp = bin_lift(parent);
  for (int k = LOG; k >= 0; --k) {
    int x = jmp[u][k];
    if (d[x] >= d[v])
      u = x;
  }
  if (u == v)
    return v;
  for (int k = LOG; k >= 0; --k) {
    int x = jmp[u][k];
    int y = jmp[v][k];
    if (x != y) {
      u = x;
      v = y;
    }
  }
  return parent[u];
}

signed main() { return 0; }

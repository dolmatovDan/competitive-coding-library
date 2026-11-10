#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> topsort, used;
void dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  topsort.push_back(v);
}

signed main() {}

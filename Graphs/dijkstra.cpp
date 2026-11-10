#include <bits/stdc++.h>

using namespace std;
#define sz(a) ((int)((a).size()))
typedef long long ll;
const int MAX = 2e8;

int dejkstra(vector<vector<pair<int, int>>> g, int start, int finish) {
  int n = sz(g);
  set<pair<int, int>> s;
  s.insert(make_pair(0, start));
  vector<int> d(n, MAX);
  d[start] = 0;
  while (not s.empty()) {
    int mn = (*s.begin()).second;
    s.erase(*s.begin());
    for (pair<int, int> e : g[mn]) {
      if (d[e.first] > d[mn] + e.second) {
        s.erase(make_pair(d[e.first], e.first));
        d[e.first] = d[mn] + e.second;
        s.insert(make_pair(d[e.first], e.first));
      }
    }
  }
  if (d[finish] == MAX)
    return -1;
  else
    return d[finish];
}

int solve() {
  int n, start, finish;
  cin >> n >> start >> finish;
  start--, finish--;
  vector<vector<pair<int, int>>> g(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      cin >> x;
      if (x != -1 and x != 0) {
        g[i].push_back(make_pair(j, x));
      }
    }
  }
  cout << dejkstra(g, start, finish) << endl;
  return 0;
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
}

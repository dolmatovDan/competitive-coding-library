#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> m(n, vector<int>(n));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }
  vector<vector<int>> d = m;
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << d[i][j] << ' ';
    }
    cout << '\n';
  }
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

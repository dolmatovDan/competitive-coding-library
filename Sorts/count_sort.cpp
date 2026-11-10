#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define sz(a) ((int)((a).size()))

void count_sort(vector<int> &a) {
  vector<int> res;
  int mx = a[max_element(all(a)) - a.begin()];
  int mn = a[min_element(all(a)) - a.begin()];
  if (mn > 0)
    mn = 0;
  vector<int> x(mx + 1 - mn);
  for (int i = 0; i < sz(a); i++) {
    x[a[i] - mn]++;
  }
  for (int i = 0; i < sz(x); i++) {
    if (x[i]) {
      for (int j = 0; j < x[i]; j++)
        res.push_back(i + mn);
    }
  }
  for (int i = 0; i < sz(res); i++)
    a[i] = res[i];
}

int solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  count_sort(a);
  for (int i = 0; i < n; i++)
    cout << a[i] << ' ';
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

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1000000007;
vector<int> power;
int x = 51;

vector<int> get_prefs(string s) {
  int n = (s.size());
  vector<int> h(n + 1);
  h[0] = 0;
  for (int i = 0; i < n; i++) {
    h[i + 1] = (((h[i] * x) % MOD + MOD) % MOD + (s[i] - 'A' + 1)) % MOD;
  }
  return h;
}

int get_hash(vector<int> &h, int l, int r) {
  return (h[r] - h[l - 1] * power[r - l + 1] % MOD + MOD) % MOD;
}

void solve() {
  return;
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
  return 0;
}

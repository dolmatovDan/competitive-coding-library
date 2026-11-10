#include <bits/stdc++.h>
using namespace std;

vector<bool> sieve1(int n) {
  vector<bool> sieve(n + 1, true);
  sieve[1] = false;
  for (int i = 2; i * i <= n; ++i) {
    if (sieve[i]) {
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }
  return sieve;
}

vector<int> sieve2(int n) {
  vector<bool> sieve(n + 1, true);
  sieve[1] = false;
  vector<int> res;
  for (int i = 2; i <= n; ++i) {
    if (sieve[i]) {
      res.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        sieve[j] = false;
      }
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a = sieve2(n);
  for (int &x : a)
    cout << x << '\n';
  return 0;
}

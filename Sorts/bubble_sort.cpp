#include <bits/stdc++.h>
using namespace std;
#define sz(a) ((int)((a).size()))
typedef long long ll;
typedef long double ld;

void bubble_sort(vector<int> &A) {
  int i = 0;
  bool flag = false;
  int cnt = 0;
  while (not flag) {
    flag = true;
    for (int i = 0; i < sz(A) - 1 - cnt; i++) {
      if (A[i] > A[i + 1]) {
        swap(A[i], A[i + 1]);
        flag = false;
      }
    }
    cnt++;
  }
}

signed main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  bubble_sort(A);
  for (int i = 0; i < n; i++)
    cout << A[i] << ' ';

  return 0;
}

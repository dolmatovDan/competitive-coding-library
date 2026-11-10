#include <bits/stdc++.h>
using namespace std;

void bingen(int n, string prefix) {
  if (n == 0) {
    cout << prefix << endl;
  } else {
    bingen(n - 1, prefix + '0');
    bingen(n - 1, prefix + '1');
  }
}

int main() {
  bingen(4, "");
  return 0;
}

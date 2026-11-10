#include <bits/stdc++.h>
using namespace std;

void gen(int length, int base, vector<int> &digits) {
  if (digits.size() == length) {
    for (auto x : digits) {
      cout << x;
    }
    cout << endl;
  } else {
    for (int k = 0; k < base; k++) {
      digits.push_back(k);
      gen(length, base, digits);
      digits.pop_back();
    }
  }
}

int main() {
  vector<int> digits;
  gen(3, 2, digits);

  return 0;
}

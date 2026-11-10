#include <bits/stdc++.h>
using namespace std;

void gen_permutations(int length, vector<int> &permutation) {
  if (permutation.size() == length) {
    for (auto x : permutation) {
      cout << x;
    }
    cout << endl;
  } else {
    for (int k = 0; k < length; k++) {
      if (find(permutation.begin(), permutation.end(), k) ==
          permutation.end()) {
        permutation.push_back(k);
        gen_permutations(length, permutation);
        permutation.pop_back();
      }
    }
  }
}

int main() {
  vector<int> perm;
  gen_permutations(10, perm);

  return 0;
}

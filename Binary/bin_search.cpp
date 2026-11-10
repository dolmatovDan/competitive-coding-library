#include <bits/stdc++.h>
using namespace std;

int bin_search_left(int x, vector<int> &A) {
  int left = -1;
  int right = A.size();
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (A[middle] < x) {
      left = middle;
    } else { // A[middle] >= x
      right = middle;
    }
  }
  return left;
}

int bin_search_right(int x, vector<int> A) {
  int left = -1;
  int right = A.size();
  while (right - left > 1) {
    int middle = (left + right) / 2;
    if (A[middle] <= x) {
      left = middle;
    } else { // A[middle] > x
      right = middle;
    }
  }
  return right;
}

int main() {
  int x;
  cin >> x;

  vector<int> A = {2, 2, 4, 5, 5, 5, 7, 7, 7, 7};

  int left = bin_search_left(x, A);
  int right = bin_search_right(x, A);
  cout << left << '\t' << right;
  return 0;
}

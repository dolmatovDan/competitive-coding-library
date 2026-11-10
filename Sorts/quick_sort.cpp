#include <bits/stdc++.h>
using namespace std;
vector<int> input_vector() {
  string line;
  getline(cin, line);
  stringstream line_stream(line);
  vector<int> A;
  while (not line_stream.eof()) {
    int x;
    line_stream >> x;
    A.push_back(x);
  }
  return A;
}

void print_vector(const vector<int> &A) {
  for (auto &x : A) {
    cout << x << ' ';
  }
  cout << '\n';
}
void qsort(vector<int> &arr, int l_hold, int r_hold) {
  int left = l_hold, right = r_hold;
  int piv =
      arr[(left + right) / 2];
  while (left <= right) {
    while (arr[left] < piv)
      left++;
    while (arr[right] > piv)
      right--;
    if (left <= right)
      swap(arr[left++], arr[right--]);
  }
  if (l_hold < right)
    qsort(arr, l_hold, right);
  if (r_hold > left)
    qsort(arr, left, r_hold);
}
int main() {
  vector<int> A = input_vector();
  qsort(A, 0, A.size() - 1);
  print_vector(A);

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef int Data_t;

vector<Data_t> input_vector();

void print_vector(const vector<int> &A);

void heap_sort(vector<Data_t> &A);

int main() {
  vector<Data_t> A = input_vector();
  heap_sort(A);
  print_vector(A);

  return 0;
}

void heap_sort(vector<Data_t> &A) {
  if (A.size() <= 1)
    return;

  for (size_t k = 1; k < A.size(); k++) {
    size_t i = k;
    size_t parent_index = (i - 1) / 2;
    while (i != 0 and A[i] > A[parent_index]) {
      swap(A[i], A[parent_index]);
      i = parent_index;
      parent_index = (i - 1) / 2;
    }
  }

  for (size_t top = A.size() - 1; top > 0; top--) {
    swap(A[0], A[top]);
    size_t i = 0;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    while ((left < top) and (A[left] > A[i]) or
           (right < top) and (A[right] > A[i])) {
      if ((right >= top) or (A[left] > A[right])) {
        swap(A[left], A[i]);
        i = left;
      } else {
        swap(A[right], A[i]);
        i = right;
      }
      left = 2 * i + 1;
      right = 2 * i + 2;
    }
  }
}

vector<Data_t> input_vector() {
  string line;
  getline(cin, line);
  stringstream line_stream(line);
  vector<Data_t> A;
  while (not line_stream.eof()) {
    Data_t x;
    line_stream >> x;
    A.push_back(x);
  }
  return A;
}

void print_vector(const vector<Data_t> &A) {
  for (auto &x : A) {
    cout << x << ' ';
  }
  cout << '\n';
}

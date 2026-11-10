#include <iostream>
using namespace std;

int64_t cnk(int64_t n, int64_t k) {
  int64_t res = 1;
  for (int64_t i = 0; i < k; i++) {
    res *= n - i;
  }
  for (int64_t i = 0; i < k; i++) {
    res /= k - i;
  }
  return res;
}

int64_t pow(int64_t n, int64_t k) {
  int64_t res = 1;
  for (int i = 0; i < k; i++) {
    res *= n;
  }
  return res;
}

int main() {
  int64_t n = 1111111111;
  int a = 2;
  while (a * a <= n) {
    if (n % a == 0)
      cout << "YES" << endl;
    a++;
  }

  return 0;
}

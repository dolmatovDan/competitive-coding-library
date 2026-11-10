#include <iostream>
using namespace std;

double fast_pow(double a, int n) {
  if (n == 0) {
    return 1;
  } else if (n % 2 == 0) {
    return fast_pow(a * a, n / 2);
  } else {
    return fast_pow(a, n - 1) * a;
  }
}

int main() {
  cout << fast_pow(2, 1000);
  return 0;
}

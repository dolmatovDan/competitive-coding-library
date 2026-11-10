#include <bits/stdc++.h>
using namespace std;

double f(double x) { return (x - 12.3456789) * (x - 0.123456789); }

int main() {
  double a, b;
  cin >> a >> b;
  double error;
  cout << "Enter needed error";
  cin >> error;

  if (f(a) * f(b) < 0) {
    while (b - a > error * 2.) {
      double c = (a + b) / 2.;
      if (f(c) == 0) {
        break;
      }
      if (f(a) * f(c) < 0) {
        b = c;
      } else {
        a = c;
      }
    }

    cout << setprecision(17) << "Answer" << (a + b) / 2;
  } else {
    cout << "Can't use binsearch of root. f(a) * f(b) >= 0" << '\n';
  }

  return 0;
}

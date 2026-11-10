#include <iostream>
using namespace std;
int main() {
  int N = 10;
  const int Q_size = 5;
  int Q[Q_size];
  for (int i = 0; i < Q_size; i++) {
    cin >> Q[i];
  }
  int Q_end = 0;

  int max_pair_sum = -1;
  int x, y;

  for (int i = Q_size; i < N; i++) {
    int current;
    cin >> current;

    int number_leaving_queue = Q[Q_end];
    Q[Q_end++] = current;
    if (Q_end > Q_size)
      Q_end = 0;

    int max_from_bypassed_numbers = -1;
    if (number_leaving_queue > max_from_bypassed_numbers) {
      max_from_bypassed_numbers = number_leaving_queue;
    }
    int pair_sum = current + max_from_bypassed_numbers;

    if (pair_sum > max_pair_sum) {
      max_pair_sum = pair_sum;
      x = current;
      y = max_from_bypassed_numbers;
    }
  }
  cout << max_pair_sum;
  return 0;
}

#include <iostream>
#include <vector>
using namespace std;
typedef int HeapData_t;
typedef vector<HeapData_t> Heap_t;

HeapData_t top(const Heap_t &h);

HeapData_t pop(Heap_t &h);

void push(Heap_t &h, HeapData_t x);

bool heap_empty(Heap_t &h);

int main() {
  Heap_t my_heap;

  HeapData_t x;
  cin >> x;
  while (x != 0) {
    push(my_heap, x);
    cin >> x;
  }

  while (not heap_empty(my_heap)) {
    cout << pop(my_heap) << '\t';
  }
  cout << '\n';

  return 0;
}

HeapData_t top(const Heap_t &h) { return h[0]; }

HeapData_t pop(Heap_t &h) {
  if (heap_empty(h))
    throw std::runtime_error("Pop on empty heap.");

  HeapData_t value = h[0];
  h[0] = h.back();
  h.pop_back();
  Heap_t::size_type i = 0;
  Heap_t::size_type left = 2 * i + 1;
  Heap_t::size_type right = 2 * i + 2;
  while ((left < h.size()) and (h[left] > h[i]) or
         (right < h.size()) and (h[right] > h[i])) {
    if ((right >= h.size()) or (h[left] > h[right])) {
      swap(h[left], h[i]);
      i = left;
    } else {
      swap(h[right], h[i]);
      i = right;
    }
    left = 2 * i + 1;
    right = 2 * i + 2;
  }
  return value;
}

void push(Heap_t &h, HeapData_t x) {
  h.push_back(x);
  Heap_t::size_type i = h.size() - 1;
  Heap_t::size_type parent_index = (i - 1) / 2;
  while (i != 0 and h[i] > h[parent_index]) {
    swap(h[i], h[parent_index]);
    i = parent_index;
    parent_index = (i - 1) / 2;
  }
}

bool heap_empty(Heap_t &h) { return h.size() == 0; }

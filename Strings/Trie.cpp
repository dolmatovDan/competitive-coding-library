#include <bits/stdc++.h>
using namespace std;
const int k = 26;

struct Node {
  Node *to[k];
  bool terminal = 0;
};

void add(Node *root, string &s) {
  auto v = root;
  for (char c : s) {
    int c1 = c - 'a';
    if (v->to[c1] == nullptr) {
      v->to[c1] = new Node();
    }
    v = v->to[c1];
  }
  v->terminal = true;
}
bool find(Node *root, string &s) {
  auto v = root;
  for (char c : s) {
    int c1 = c - 'a';
    if (v->to[c1] == nullptr) {
      return false;
    }
    v = v->to[c1];
  }
  return v->terminal;
}
void erase(Node *root, string &s) {
  auto v = root;
  for (char c : s) {
    v = v->to[c - 'a'];
  }
  v->terminal = false;
}
int main() {
  Node *root = new Node();
  return 0;
}

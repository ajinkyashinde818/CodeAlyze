#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node* l = nullptr;
  Node* r = nullptr;
};

int n;
long k;
string s[100000];
Node nodes[400000];
Node* head = nodes;

Node* new_node() {
  static Node* node = nodes;
  return ++node;
}

void add(const string& str) {
  Node* curr = head;
  for (int i = 0; i < str.size(); ++i) {
    char c = str[i];
    if (c == '0') {
      if (curr->l == nullptr) {
        curr->l = new_node();
      }
      curr = curr->l;
    } else {
      if (curr->r == nullptr) {
        curr->r = new_node();
      }
      curr = curr->r;
    }
  }
}

void create() {
  for (int i = 0; i < n; ++i) {
    add(s[i]);
  }
}

const int L = 100005;
int a[L];
void rec(Node* node, int level) {
  if (node == nullptr) {
    ++a[level];
    return;
  }
  
  if (node->l == nullptr && node->r == nullptr) return;
  rec(node->l, level + 1);
  rec(node->r, level + 1);
}

const int M = 64;
int b[M];
bool ok() {
  for (int i = 0; i < min<long>(k + 1, L); ++i) {
    if (a[i] % 2 == 0) continue;
    long p = k - i + 1;
    int cnt = 0;
    while (p % 2 == 0) {
      p /= 2;
      ++cnt;
    }
    ++b[cnt];
  }
  
  for (int p = 0; p < M; ++p) {
    if (b[p] % 2 == 1) return false;
  }
  return true;
}

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  create();
  rec(head, 0);
  
  if (ok()) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
  }
  
  return 0;
}

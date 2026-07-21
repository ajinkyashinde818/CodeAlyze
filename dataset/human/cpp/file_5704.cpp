#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;

struct Trie {
  Trie *child[2];
  Trie() { child[0] = child[1] = nullptr; }
  void insert(const string &s) {
    Trie *node = this;
    for (char c : s) {
      int k = c - '0';
      if (node->child[k] == nullptr) {
        node->child[k] = new Trie();
      }
      node = node->child[k];
    }
  }
};

ll grundy(Trie *node, ll L) {
  if (node == nullptr) {
    return L & -L;
  }
  return grundy(node->child[0], L - 1) ^ grundy(node->child[1], L - 1);
}

int main() {
  int N;
  ll L;
  cin >> N >> L;
  Trie *trie = new Trie();
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    trie->insert(s);
  }
  cout << (grundy(trie, L + 1) != 0 ? "Alice" : "Bob") << endl;
  return 0;
}

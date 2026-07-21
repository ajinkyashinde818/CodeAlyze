#include<bits/stdc++.h>
using namespace std;

using I = long long;

I Grundy(auto n) {
  if(n == 0) return 0;
  for(auto i=0; i<60; ++i) if((n>>i) & 1) return 1ll << i;
  assert(false);
}

#include<memory>
#include<unordered_map>
template<typename T> class Trie {
 public:
  bool solve(auto L) {
    return traverse(root_, L+1);
  }
  I traverse(const auto& n, auto L) {
    if(!n) return Grundy(L);
    if(n->value) return 0;
    return traverse(n->child['0'], L-1) ^ traverse(n->child['1'], L-1);
  }
  void insert(const std::string& s, const T& value) {insert(root_, s, 0, value);}
 private:
  struct Node {
    T value;
    std::unordered_map<T, std::unique_ptr<Node>> child;
  };
  void insert(std::unique_ptr<Node>& node, const std::string& s, int i, const T& v) {
    if(!node) node = std::make_unique<Node>();
    if(i == s.size()) node->value = v;
    else insert(node->child[s[i]], s, i + 1, v);
  }
  std::unique_ptr<Node> root_;
};

int main() {
  I N, L;
  cin >> N >> L;
  vector<string> S(N);
  for(auto& i: S) cin >> i;
  Trie<int> T;
  for(auto i: S) T.insert(i, 1);
  cout << (T.solve(L) ? "Alice" : "Bob") << endl;
}

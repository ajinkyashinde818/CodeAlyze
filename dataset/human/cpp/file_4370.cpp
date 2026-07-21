#include<unordered_map>
#include<utility>
template<typename T>
class UnionFind {
 public:
  void unite(const T& a, const T& b) {
    auto x = find(a), y = find(b);
    if(rank_[x] < rank_[y]) std::swap(x, y);
    parent_[y] = x;
    if(rank_[x] == rank_[y]) rank_[x] += 1;
  }
  T find(const T& x) {
    if(!parent_.count(x)) {
      rank_[x] = 1;
      return parent_[x] = x;
    }
    return (parent_[x] == x) ? x : (parent_[x] = find(parent_[x]));
  }
 private:
  std::unordered_map<T, T> parent_;
  std::unordered_map<T, int> rank_;
};

#include<bits/stdc++.h>
using namespace std;

int sum(auto v) {
  return accumulate(begin(v), end(v), 0, [](auto sum, auto i) {return sum ^= i;});
}

bool neq(auto a, auto b) {
  sort(begin(a), end(a));
  sort(begin(b), end(b));
  return a != b;
}

int solve(auto a, auto b) {
  a.emplace_back(sum(a));
  b.emplace_back(sum(b));

  if(neq(a, b)) return -1;

  auto res = 0;
  set<int> used;
  UnionFind<int> g;
  for(auto i = 0; i < a.size() - 1; ++i) if(a[i] != b[i]) {
    ++res;
    used.emplace(a[i]);
    used.emplace(b[i]);
    g.unite(b[i], a[i]);
  }
  used.emplace(a.back());
  used.emplace(b.back());
  g.unite(b.back(), a.back());
  return res + count_if(begin(used), end(used), [&](auto i) {return i == g.find(i);}) - 1;
}

int main() {
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for(auto p: {&a, &b}) for(auto& i: *p) cin >> i;
  cout<< solve(a, b) << endl;
}

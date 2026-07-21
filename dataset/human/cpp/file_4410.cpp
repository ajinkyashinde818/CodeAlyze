#include <iostream>
#include <algorithm>
#include <utility>
#include <numeric>
#include <vector>
#include <array>
#include <map>

class union_find {
private:
  size_t component;
  std::vector<int32_t> parent;

public:
  union_find() = default;
  union_find(size_t size_) { init(size_); }

  void init(size_t size_) {
    component = size_;
    parent.assign(size_, -1);
  }

  size_t count_components() const { 
    return component; 
  }
  size_t component_size(size_t i) { 
    return -parent[find_parent(i)]; 
  }
  bool same_component(size_t i, size_t j) { 
    return find_parent(i) == find_parent(j); 
  }

  size_t find_parent(size_t i) {
    if (parent[i] < 0) {
      return i;
    }
    else {
      return parent[i] = find_parent(parent[i]);
    }
  }

  bool unite(size_t i, size_t j) {
    i = find_parent(i);
    j = find_parent(j);
    if (i == j) {
      return false;
    }
    if (parent[i] > parent[j]) {
      std::swap(i, j);
    }
    parent[i] += parent[j];
    parent[j] = i;
    --component;
    return true;
  }

};

using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;

constexpr i32 inf32 = (i32(1) << 30) - 1;
constexpr i64 inf64 = (i64(1) << 62) - 1;

int main() {
  size_t N;
  u32 X = 0;
  std::vector<u32> A, B;
  {
    std::cin >> N;
    std::vector<u32> A_(N + 1), B_(N + 1);
    for (size_t i = 0; i < N; ++i) {
      std::cin >> A_[i];
      A_.back() ^= A_[i];
    }
    for (size_t i = 0; i < N; ++i) {
      std::cin >> B_[i];
      B_.back() ^= B_[i];
    }
    X = A_.back();
    for (size_t i = 0; i < N; ++i) {
      if (A_[i] != B_[i]) {
        A.push_back(A_[i]);
        B.push_back(B_[i]);
      }
    }
    N = A.size();
    std::sort(A_.begin(), A_.end());
    std::sort(B_.begin(), B_.end());
    if (A_ != B_) {
      std::cout << "-1\n";
      return 0;
    }
  }
  u32 ans = N, subtract = 0;
  std::map<u32, std::vector<u32>> idx;
  union_find uni(N);
  for (size_t i = 0; i < N; ++i) {
    idx[B[i]].push_back(i);
  }
  for (const auto &p: idx) {
    for (size_t i = 1; i < p.second.size(); ++i) {
      uni.unite(p.second[i - 1], p.second[i]);
    }
  }
  for (size_t i = 0; i < N; ++i) {
    if (B[i] == X) {
      subtract = 1;
    }
    if (!idx[A[i]].empty()) {
      uni.unite(i, idx[A[i]].back());
      idx[A[i]].pop_back();
    }
  }
  std::cout << ans + uni.count_components() - subtract << '\n';
  return 0;
}

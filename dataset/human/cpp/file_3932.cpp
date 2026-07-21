#include <cstdio>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <climits>
#include <algorithm>
#include <memory>
#include <utility>
#include <list>
#include <vector>
#include <functional>
#include <complex>
#include <tuple>

constexpr intmax_t  operator ""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator ""_ju(unsigned long long n) { return n; }
constexpr size_t    operator ""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

template <typename Key, typename Compare = std::less<>>
class heap {
public:
  using size_type = size_t;
  using key_type = Key;
  using mapped_type = size_type;
  using value_type = std::pair<key_type, size_type>;
  using reference = value_type&;
  using const_reference = value_type const&;
  using key_compare = Compare;
  class node_handle;

private:
  size_type M_size = 0;
  Compare M_comp;
  std::vector<value_type> M_c;
  std::vector<size_type> M_rev;

public:
  heap() = default;
  heap(heap const&) = default;
  heap(heap&&) = default;
  heap& operator =(heap const& other) = default;
  heap& operator =(heap&&) = default;

  heap(size_type n): M_c(n+1), M_rev(n+1, -1) {}

  size_type size() const noexcept { return M_size; }
  [[nodiscard]] bool empty() const noexcept { return M_size == 0; }

  const_reference const& top() const { return M_c[1]; }
  void pop() {
    M_rev[M_c[1].second] = -1;  // old one
    std::swap(M_c[1], M_c[M_size]);
    M_rev[M_c[1].second] = 1;  // new one
    --M_size;
    size_type i = 1;
    while (true) {
      size_type left = i << 1;
      size_type right = left + 1;
      size_type swap = -1;
      if (left <= M_size && M_comp(M_c[i].first, M_c[left].first)) {
        swap = left;
      }
      if (right <= M_size && M_comp(M_c[i].first, M_c[right].first)) {
        if (swap == -1_zu || M_comp(M_c[left].first, M_c[right].first))
          swap = right;
      }
      if (swap == -1_zu) break;

      std::swap(M_c[i], M_c[swap]);
      std::swap(M_rev[M_c[i].second], M_rev[M_c[swap].second]);
      i = swap;
    }
  }
  void push(key_type const& key, mapped_type const& mapped) {
    ++M_size;
    M_c[M_size] = std::make_pair(key, mapped);
    M_rev[mapped] = M_size;
    size_type i = M_size;
    while (i > 1) {
      size_type parent = i >> 1;
      if (!M_comp(M_c[parent].first, M_c[i].first)) break;
      std::swap(M_c[i], M_c[parent]);
      std::swap(M_rev[M_c[i].second], M_rev[M_c[parent].second]);
      i = parent;
    }
  }
  void prioritize(mapped_type& mapped, mapped_type const& key) {
    size_type i = M_rev[mapped];
    assert(M_c[i].second == mapped);
    assert(!M_comp(key, M_c[i].first));
    M_c[i].first = key;
    while (i > 1) {
      size_type parent = i >> 1;
      if (!M_comp(M_c[parent].first, M_c[i].first)) break;
      std::swap(M_c[i], M_c[parent]);
      std::swap(M_rev[M_c[i].second], M_rev[M_c[parent].second]);
      i = parent;
    }
  }
};

template <typename WeightType>
class weighted_edge {
public:
  using size_type = size_t;
  using weight_type = WeightType;

protected:
  size_type M_src, M_dst;
  weight_type M_weight;

public:
  weighted_edge() = default;
  weighted_edge(weighted_edge const&) = default;
  weighted_edge(weighted_edge&&) = default;

  weighted_edge(size_type s, size_type d, weight_type w):
    M_src(s), M_dst(d), M_weight(w)
  {}

  weighted_edge& operator =(weighted_edge const&) = default;
  weighted_edge& operator =(weighted_edge&&) = default;

  bool operator <(weighted_edge const& other) const {
    if (M_weight < other.M_weight) return true;
    if (other.M_weight < M_weight) return false;
    if (M_src != other.M_src) return M_src < other.M_src;
    return M_dst < other.M_dst;
  }

  size_type source() const { return M_src; }
  size_type target() const { return M_dst; }
  weight_type weight() const { return M_weight; }
};

struct directed_tag {};
struct undirected_tag {};

template <typename Edge, typename Directedness>
class adjacency_list {
public:
  using size_type = size_t;
  using edge_type = Edge;
  using weight_type = typename Edge::weight_type;
  static constexpr weight_type inf = std::numeric_limits<weight_type>::max();

private:
  std::vector<std::vector<edge_type>> M_g;

public:
  adjacency_list() = default;
  adjacency_list(adjacency_list const&) = default;
  adjacency_list(adjacency_list&&) = default;
  adjacency_list(size_type n): M_g(n) {}

  template <typename... Args>
  void emplace(size_type src, size_type dst, Args... args) {
    M_g[src].emplace_back(src, dst, args...);
    if (std::is_same<Directedness, undirected_tag>::value)
      M_g[dst].emplace_back(dst, src, args...);
  }

  size_type size() const { return M_g.size(); }
  std::vector<edge_type> const& operator [](size_type i) const { return M_g[i]; }
};

template <typename Edge, typename Directedness>
constexpr typename Edge::weight_type adjacency_list<Edge, Directedness>::inf;

struct dijkstra_tag {} dijkstra;

template <typename Edge, typename Directedness>
auto shortest(adjacency_list<Edge, Directedness> const& g, size_t s, dijkstra_tag) {
  using weight_type = typename Edge::weight_type;
  size_t n = g.size();
  std::vector<weight_type> dp(n, g.inf);
  dp[s] = weight_type(0);
  using heap = heap<weight_type, std::greater<>>;
  heap h(n);
  h.push(weight_type(0), s);
  std::vector<bool> pushed(n);
  while (!h.empty()) {
    weight_type w;
    size_t v;
    std::tie(w, v) = h.top();
    h.pop();
    pushed[v] = false;
    if (dp[v] < w) continue;
    for (auto const& e: g[v]) {
      weight_type nw = dp[e.source()] + e.weight();
      size_t nv = e.target();
      if (nw < dp[nv]) {
        dp[nv] = nw;
        if (!pushed[nv]) {
          h.push(nw, nv);
          pushed[nv] = true;
        } else {
          h.prioritize(nv, nw);
        }
      }
    }
  }
  return dp;
}

int main() {
  double xs, ys, xt, yt;
  scanf("%lf %lf %lf %lf", &xs, &ys, &xt, &yt);

  size_t n;
  scanf("%zu", &n);

  std::vector<std::pair<std::complex<double>, double>> c(n);
  for (auto& ci: c) {
    double x, y, r;
    scanf("%lf %lf %lf", &x, &y, &r);

    std::complex<double> z(x, y);
    ci = std::make_pair(z, r);
  }
  c.emplace_back(std::complex<double>(xs, ys), 0.0);
  c.emplace_back(std::complex<double>(xt, yt), 0.0);
  n += 2;

  adjacency_list<weighted_edge<double>, undirected_tag> g(n);
  for (size_t i = 0; i < n; ++i) {
    std::complex<double> zi;
    double ri;
    std::tie(zi, ri) = c[i];
    for (size_t j = 0; j < i; ++j) {
      std::complex<double> zj;
      double rj;
      std::tie(zj, rj) = c[j];

      double w = std::max(0.0, std::abs(zi-zj) - (ri+rj));
      g.emplace(i, j, w);
    }
  }

  printf("%.12f\n", shortest(g, n-2, dijkstra)[n-1]);
}

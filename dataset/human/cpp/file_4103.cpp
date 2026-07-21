/*

https://atcoder.jp/contests/arc064/submissions/8199522

*/

#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <functional>
#include <list>
#include <memory>
#include <tuple>
#include <utility>
#include <vector>

constexpr intmax_t operator""_jd(unsigned long long n) { return n; }
constexpr uintmax_t operator""_ju(unsigned long long n) { return n; }
constexpr size_t operator""_zu(unsigned long long n) { return n; }
// constexpr ptrdiff_t operator ""_td(unsigned long long n) { return n; }

#include <cstddef>
#include <functional>
#include <vector>

template <class Key, class Compare = std::less<Key>> class heap {
private:
  using size_type = std::size_t;
  class node_type;
  using pointer = node_type *;
  class node_type {
    friend heap;
    Key key;
    pointer next, head, parent;
  };

  Compare M_comp;
  std::vector<node_type> M_c;
  pointer root;

  pointer merge(pointer x, pointer y) {
    // if(!x){return y;}
    // if(!y){return x;}
    if (M_comp(x->key, y->key)) {
      std::swap(x, y);
    }
    y->next = x->head;
    if (x->head) {
      x->head->parent = y;
    }
    x->head = y;
    y->parent = x;
    return x;
  }

  pointer merge_list(pointer x) {
    if (!x) {
      return nullptr;
    }
    pointer s = nullptr;
    while (x && x->next) {
      pointer t = x->next;
      pointer n = t->next;
      x = merge(x, t);
      x->next = s;
      s = x;
      x = n;
    }
    if (!x) {
      x = s;
      s = s->next;
    }
    while (s) {
      pointer t = s->next;
      x = merge(x, s);
      s = t;
    }
    x->next = nullptr;
    return x;
  }

public:
  heap(size_type n) : M_comp(), M_c(n), root(nullptr) {}
  bool empty() const noexcept { return !root; }

  std::pair<Key, size_type> top() const {
    return {root->key, root - M_c.data()};
  }
  void pop() { root = merge_list(root->head); }
  void push(const Key &key, const size_type mapped) {
    const pointer ptr = M_c.data() + mapped;
    ptr->key = key;
    ptr->next = nullptr;
    ptr->head = nullptr;
    ptr->parent = nullptr;

    if (root) {
      root = merge(root, ptr);
    } else {
      root = ptr;
    }
  }
  void prioritize(const size_type mapped, const Key &key) {
    const pointer ptr = M_c.data() + mapped;
    ptr->key = key;
    if (root == ptr) {
      return;
    }
    const pointer pp = ptr->parent;
    if (pp->head == ptr) {
      pp->head = ptr->next;
    } else {
      pp->next = ptr->next;
    }
    if (ptr->next) {
      ptr->next->parent = pp;
      ptr->next = nullptr;
    }
    root = merge(root, ptr);
  }
};

template <typename WeightType> class weighted_edge {
public:
  using size_type = size_t;
  using weight_type = WeightType;

protected:
  size_type M_src, M_dst;
  weight_type M_weight;

public:
  weighted_edge() = default;
  weighted_edge(weighted_edge const &) = default;
  weighted_edge(weighted_edge &&) = default;

  weighted_edge(size_type s, size_type d, weight_type w)
      : M_src(s), M_dst(d), M_weight(w) {}

  weighted_edge &operator=(weighted_edge const &) = default;
  weighted_edge &operator=(weighted_edge &&) = default;

  bool operator<(weighted_edge const &other) const {
    if (M_weight < other.M_weight)
      return true;
    if (other.M_weight < M_weight)
      return false;
    if (M_src != other.M_src)
      return M_src < other.M_src;
    return M_dst < other.M_dst;
  }

  size_type source() const { return M_src; }
  size_type target() const { return M_dst; }
  weight_type weight() const { return M_weight; }
};

struct directed_tag {};
struct undirected_tag {};

template <typename Edge, typename Directedness> class adjacency_list {
public:
  using size_type = size_t;
  using edge_type = Edge;
  using weight_type = typename Edge::weight_type;
  static constexpr weight_type inf = std::numeric_limits<weight_type>::max();

private:
  std::vector<std::vector<edge_type>> M_g;

public:
  adjacency_list() = default;
  adjacency_list(adjacency_list const &) = default;
  adjacency_list(adjacency_list &&) = default;
  adjacency_list(size_type n) : M_g(n) {}

  template <typename... Args>
  void emplace(size_type src, size_type dst, Args... args) {
    M_g[src].emplace_back(src, dst, args...);
    if (std::is_same<Directedness, undirected_tag>::value)
      M_g[dst].emplace_back(dst, src, args...);
  }

  size_type size() const { return M_g.size(); }
  std::vector<edge_type> const &operator[](size_type i) const { return M_g[i]; }
};

template <typename Edge, typename Directedness>
constexpr typename Edge::weight_type adjacency_list<Edge, Directedness>::inf;

struct dijkstra_tag {
} dijkstra;

template <typename Edge, typename Directedness>
auto shortest(adjacency_list<Edge, Directedness> const &g, size_t s,
              dijkstra_tag) {
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
    if (dp[v] < w)
      continue;
    for (auto const &e : g[v]) {
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
  for (auto &ci : c) {
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

      double w = std::max(0.0, std::abs(zi - zj) - (ri + rj));
      g.emplace(i, j, w);
    }
  }

  printf("%.12f\n", shortest(g, n - 2, dijkstra)[n - 1]);
}

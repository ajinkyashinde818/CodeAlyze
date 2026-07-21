#include<iostream>
#include<memory>
using Size = long long;
template<typename T> class SegmentTree {
 public:
  SegmentTree(Size SIZE, T INF) : SIZE(SIZE), INF(INF), ROOT(std::make_unique<Node>(0, INF)) {
    ROOT->update = 0;
  }
  void update(Size a, Size b, T v) {update(a, b, v, ROOT, 0, SIZE);}
  void add(Size a, Size b, T v) {add(a, b, v, ROOT, 0, SIZE);}
  T sum(Size a, Size b) {return query(a, b).sum;}
  T min(Size a, Size b) {return query(a, b).min;}
  T max(Size a, Size b) {return query(a, b).max;}
  Size lower_bound(Size a, Size b, T v) {return lower_bound(a, b, v, ROOT, 0, SIZE);}
  void debug() {
    traverse(ROOT, 0, SIZE, 0);
  }
  void traverse(const auto& n, Size l, Size r, Size d) {
    // LEAF
//     push(n, l, r);
//     auto m = (l + r) / 2;
//     if(l + 1 == r) std::cout << n->sum << " : " << n->min << " : " << n->max << std::endl;
//     else {
//       traverse(n->r_child, m, r, d + 1);
//       traverse(n->l_child, l, m, d + 1);
//     }
    // ALL
    push(n, l, r);
    auto m = (l + r) / 2;
    if(l+1 != r) traverse(n->r_child, m, r, d + 1);
    for(auto i = 0; i < d; ++i) std::cout << "    ";
    std::cout << n->sum << ":" << n->min << ":" << n->max;
//     std::cout << "  " << l << " to " << r;
    std::cout << std::endl;
    if(l+1 != r) traverse(n->l_child, l, m, d + 1);
  }
 private:
  struct Node {
    T sum;
    T min;
    T max;
    T update;
    T add;
    std::unique_ptr<Node> l_child, r_child;
    Node(T v, T INF) : sum(v), min(v), max(v), update(INF), add(INF) {}
  };
  inline void push(const auto& n, Size l, Size r) {
    if(not n->l_child) n->l_child = std::make_unique<Node>(0, INF);
    if(not n->r_child) n->r_child = std::make_unique<Node>(0, INF);
    if(n->update != INF) {
      n->add = INF;
      n->l_child->update = n->r_child->update = n->update;
      n->sum = (r - l) * n->update;
      n->min = n->update;
      n->max = n->update;
      n->update = INF;
    }
    if(n->add != INF) {
      if(n->l_child->add != INF) n->l_child->add += n->add;
      else                       n->l_child->add = n->add;
      if(n->r_child->add != INF) n->r_child->add += n->add;
      else                       n->r_child->add = n->add;
      if(n->l_child->update != INF) n->l_child->update += n->add;
      if(n->r_child->update != INF) n->r_child->update += n->add;
      n->sum += (r - l) * n->add;
      n->min += n->add;
      n->max += n->add;
      n->add = INF;
    }
  }
  inline void fix(const auto& n) {
    n->sum = n->l_child->sum + n->r_child->sum;
    n->min = std::min(n->l_child->min, n->r_child->min);
    n->max = std::max(n->l_child->max, n->r_child->max);
  }
  void update(Size a, Size b, T v, const auto& n, Size l, Size r) {
    push(n, l, r);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      n->update = v;
      push(n, l, r);
      return;
    }
    auto m = (l + r) / 2;
    update(a, b, v, n->l_child, l, m);
    update(a, b, v, n->r_child, m, r);
    fix(n);
  }
  void add(Size a, Size b, T v, const auto& n, Size l, Size r) {
    push(n, l, r);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      n->add = v;
      push(n, l, r);
      return;
    }
    auto m = (l + r) / 2;
    add(a, b, v, n->l_child, l, m);
    add(a, b, v, n->r_child, m, r);
    fix(n);
  }
  Node query(Size a, Size b) {
    Node res(0, INF);
    res.min = INF;
    res.max = -INF;
    query(res, a, b, ROOT, 0, SIZE);
    return res;
  }
  void query(auto& res, Size a, Size b, const auto& n, Size l, Size r) {
    push(n, l, r);
    if(b <= l || r <= a) return;
    if(a <= l && r <= b) {
      res.sum += n->sum;
      res.min = std::min(res.min, n->min);
      res.max = std::max(res.max, n->max);
      return;
    }
    auto m = (l + r) / 2;
    query(res, a, b, n->l_child, l, m);
    query(res, a, b, n->r_child, m, r);
  }
  Size lower_bound(Size a, Size b, T v, const auto& n, Size l, Size r) {
    push(n, l, r);
    if(b <= l || r <= a) return SIZE;
    if(n->max < v) return SIZE;
    if(l + 1 == r) return l;
    auto m = (l + r) / 2;
    auto i = lower_bound(a, b, v, n->l_child, l, m);
    if(i != SIZE) return i;
    return lower_bound(a, b, v, n->r_child, m, r);
  }
  const Size SIZE;
  const T INF;
  const std::unique_ptr<Node> ROOT;
};

#include<bits/stdc++.h>
using namespace std;

using I = long long;

I solve(auto N, auto X, auto V) {
  vector<I> S(2*N + 1);
  X.insert(begin(X), 0);
  V.insert(begin(V), 0);
  S[1] = V[1];
  for(auto i=2; i<=2*N; ++i) S[i] = S[i-1] + V[i] - (X[i] - X[i-1]);
  SegmentTree<I> segtree(2*N, 1e18);
  for(auto i=0; i<2*N; ++i) segtree.update(i, i+1, S[i+1]);

  I res = 0;
  for(I l=0; l<2*N; ++l) {
    auto h = min(l+N, 2*N);
    auto m = segtree.max(l, h);
    auto r = segtree.lower_bound(l, h, m);
    I sum = S[r+1] - S[l];
    if(l==0) {
      sum -= abs(X[1]);
    } else {
      sum += X[l+1] - X[l];
      sum -= abs(X[l+1]);
    }
    res = max(res, sum);
  }
  return res;
}

int main() {
  I N, C;
  cin >> N >> C;
  vector<I> X(2*N), V(2*N);
  for(auto i=N; i<2*N; ++i) cin >> X[i] >> V[i];
  for(auto i=0; i<N; ++i) X[i] = X[i+N] - C;
  for(auto i=0; i<N; ++i) V[i] = V[i+N];

  auto res = solve(N, X, V);
  reverse(begin(X), end(X));
  reverse(begin(V), end(V));
  for(auto& i: X) i = -i;
  cout << max(res, solve(N, X, V)) << endl;
}

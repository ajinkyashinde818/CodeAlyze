#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 998244353;

const int64 infll = (1LL << 60) - 1;
const int inf = (1 << 30) - 1;

struct IoSetup {
  IoSetup() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    cerr << fixed << setprecision(10);
  }
} iosetup;


template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
  os << p.first << " " << p.second;
  return os;
}

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second;
  return is;
}

template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < (int) v.size(); i++) {
    os << v[i] << (i + 1 != v.size() ? " " : "");
  }
  return os;
}

template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(T &in : v) is >> in;
  return is;
}

template< typename T1, typename T2 >
inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }

template< typename T1, typename T2 >
inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

template< typename T = int64 >
vector< T > make_v(size_t a) {
  return vector< T >(a);
}

template< typename T, typename... Ts >
auto make_v(size_t a, Ts... ts) {
  return vector< decltype(make_v< T >(ts...)) >(a, make_v< T >(ts...));
}

template< typename T, typename V >
typename enable_if< is_class< T >::value == 0 >::type fill_v(T &t, const V &v) {
  t = v;
}

template< typename T, typename V >
typename enable_if< is_class< T >::value != 0 >::type fill_v(T &t, const V &v) {
  for(auto &e : t) fill_v(e, v);
}

template< typename F >
struct FixPoint : F {
  FixPoint(F &&f) : F(forward< F >(f)) {}

  template< typename... Args >
  decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, forward< Args >(args)...);
  }
};

template< typename F >
inline decltype(auto) MFP(F &&f) {
  return FixPoint< F >{forward< F >(f)};
}


template< class T, size_t V >
struct ArrayPool {
  array< T, V > pool;
  array< T *, V > stock;
  int ptr;

  ArrayPool() { clear(); }

  inline T *alloc() {
    return stock[--ptr];
  }

  inline void free(T *t) {
    stock[ptr++] = t;
  }

  void clear() {
    ptr = (int) pool.size();
    for(int i = 0; i < pool.size(); i++) stock[i] = &pool[i];
  }
};


struct pi {
  int64 first;
  int second;

  pi(const int64 &first, const int &second) : first(first), second(second) {}

  pi() = default;

  bool operator<(const pi &a) const {
    if(first != a.first) return first < a.first;
    return true;
  }

  bool operator>(const pi &a) const {
    if(first != a.first) return first > a.first;
    return true;
  }
};


template< typename key_t, size_t V >
struct SplayTree {

  const key_t e;

  SplayTree(const key_t &e) : pool(), e(e) {}

  struct Node {
    Node *l, *r, *p;
    key_t key, sum;

    Node() = default;

    Node(const key_t &k) : key(k), sum(k), l(nullptr), r(nullptr), p(nullptr) {}
  };

  ArrayPool< Node, V > pool;


  void rotr(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->l = t->r)) t->r->p = x;
    t->r = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  void rotl(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->r = t->l)) t->l->p = x;
    t->l = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  inline key_t sum(const Node *t) const {
    return t ? t->sum : e;
  }

  void update(Node *t) {
    t->sum = max({sum(t->l), t->key, sum(t->r)});
  }

  Node *get_left(Node *t) const {
    while(t->l) t = t->l;
    return t;
  }

  Node *get_right(Node *t) const {
    while(t->r) t = t->r;
    return t;
  }

  inline Node *alloc(const key_t &v) {
    return &(*pool.alloc() = Node(v));
  }

  void splay(Node *t) {
    while(t->p) {
      auto *q = t->p;
      if(!q->p) {
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
        if(r->l == q) {
          if(q->l == t) rotr(q), rotr(t);
          else rotl(t), rotr(t);
        } else {
          if(q->r == t) rotl(q), rotl(t);
          else rotr(t), rotl(t);
        }
      }
    }
  }

  Node *push_back(Node *t, const key_t &v) {
    if(!t) {
      t = alloc(v);
      return t;
    } else {
      Node *cur = get_right(t), *z = alloc(v);
      z->p = cur;
      cur->r = z;
      update(cur);
      splay(z);
      return z;
    }
  }

  Node *erase(Node *t) {
    splay(t);
    Node *x = t->l, *y = t->r;
    pool.free(t);
    if(!x) {
      t = y;
      if(t) t->p = nullptr;
    } else if(!y) {
      t = x;
      t->p = nullptr;
    } else {
      x->p = nullptr;
      t = get_right(x);
      splay(t);
      t->r = y;
      y->p = t;
      update(t);
    }
    return t;
  }
};


template< typename SUM, typename KEY, size_t V >
struct LinkCutTreeSubtree {

  struct Node {
    Node *l, *r, *p;

    typename SplayTree< pi, V >::Node *light, *belong;
    KEY key;
    SUM sum;

    bool rev;
    //int sz;

    Node() = default;

    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }

    Node(const KEY &key, const SUM &sum) :
        key(key), sum(sum), rev(false), belong(nullptr),
        l(nullptr), r(nullptr), p(nullptr), light(nullptr) {}
  };

  using ST = SplayTree< pi, V >;

  ST st;
  const SUM ident;
  ArrayPool< Node, V > pool;

  LinkCutTreeSubtree(const SUM &ident) : ident(ident), st(pi(-infll, -1)), pool() {}

  Node *alloc(const KEY &key) {
    auto ret = &(*pool.alloc() = Node(key, ident));
    update(ret);
    return ret;
  }

  Node *set_key(Node *t, const KEY &key) {
    expose(t);
    t->key = key;
    update(t);
    return t;
  }

  void toggle(Node *t) {
    swap(t->l, t->r);
    t->sum.toggle();
    t->rev ^= true;
  }

  void push(Node *t) {
    if(t->rev) {
      if(t->l) toggle(t->l);
      if(t->r) toggle(t->r);
      t->rev = false;
    }
  }


  void update(Node *t) {
    t->sum.merge(t->key, t->l ? t->l->sum : ident, t->r ? t->r->sum : ident, st.sum(t->light));
  }

  void rotr(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->l = t->r)) t->r->p = x;
    t->r = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }

  void rotl(Node *t) {
    auto *x = t->p, *y = x->p;
    if((x->r = t->l)) t->l->p = x;
    t->l = x, x->p = t;
    update(x), update(t);
    if((t->p = y)) {
      if(y->l == x) y->l = t;
      if(y->r == x) y->r = t;
      update(y);
    }
  }


  void splay(Node *t) {
    push(t);

    Node *rot = t;
    while(!rot->is_root()) rot = rot->p;
    t->belong = rot->belong;
    if(t != rot) rot->belong = nullptr;

    while(!t->is_root()) {
      auto *q = t->p;
      if(q->is_root()) {
        push(q), push(t);
        if(q->l == t) rotr(t);
        else rotl(t);
      } else {
        auto *r = q->p;
        push(r), push(q), push(t);
        if(r->l == q) {
          if(q->l == t) rotr(q), rotr(t);
          else rotl(t), rotr(t);
        } else {
          if(q->r == t) rotl(q), rotl(t);
          else rotr(t), rotl(t);
        }
      }
    }

  }


  Node *expose(Node *t) {
    Node *rp = nullptr;
    for(auto *cur = t; cur; cur = cur->p) {
      splay(cur);
      if(cur->r) {
        cur->light = st.push_back(cur->light, cur->r->sum.c_max);
        cur->r->belong = cur->light;
        cur->sum.add(cur->r->sum);
      }
      cur->r = rp;
      if(cur->r) {
        cur->light = st.erase(cur->r->belong);
        cur->sum.erase(cur->r->sum);
      }
      update(cur);
      rp = cur;
    }
    splay(t);
    return rp;
  }

  void link(Node *child, Node *parent) {
    expose(child);
    expose(parent);
    child->p = parent;
    parent->r = child;
    update(parent);
  }

  void cut(Node *child) {
    expose(child);
    auto *parent = child->l;
    child->l = nullptr;
    parent->p = nullptr;
    update(child);
  }

  void evert(Node *t) {
    expose(t);
    toggle(t);
    push(t);
  }

  Node *lca(Node *u, Node *v) {
    if(get_root(u) != get_root(v)) return nullptr;
    expose(u);
    return expose(v);
  }


  Node *get_kth(Node *x, int k) {
    expose(x);
    while(x) {
      push(x);
      if(x->r && x->r->sz > k) {
        x = x->r;
      } else {
        if(x->r) k -= x->r->sz;
        if(k == 0) return x;
        k -= 1;
        x = x->l;
      }
    }
    return nullptr;
  }

  Node *get_root(Node *x) {
    expose(x);
    while(x->l) {
      push(x);
      x = x->l;
    }
    return x;
  }
};


struct Scanner {
  FILE *fp = nullptr;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;

  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }

  bool succ() {
    while(true) {
      if(st == ed) {
        reread();
        if(st == ed) return false;
      }
      while(st != ed && isspace(line[st])) st++;
      if(st != ed) break;
    }
    if(ed - st <= 50) reread();
    return true;
  }

  template< class T, enable_if_t< is_same< T, string >::value, int > = 0 >
  bool read_single(T &ref) {
    if(!succ()) return false;
    while(true) {
      size_t sz = 0;
      while(st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if(!sz || st != ed) break;
      reread();
    }
    return true;
  }

  template< class T, enable_if_t< is_integral< T >::value, int > = 0 >
  bool read_single(T &ref) {
    if(!succ()) return false;
    bool neg = false;
    if(line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while(isdigit(line[st])) {
      ref = 10 * ref + (line[st++] - '0');
    }
    if(neg) ref = -ref;
    return true;
  }

  template< class T >
  bool read_single(vector< T > &ref) {
    for(auto &d : ref) {
      if(!read_single(d)) return false;
    }
    return true;
  }

  void read() {}

  template< class H, class... T >
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }

  Scanner(FILE *_fp) : fp(_fp) {}
};

struct Printer {
public:
  template< bool F = false >
  void write() {}

  template< bool F = false, class H, class... T >
  void write(const H &h, const T &... t) {
    if(F) write_single(' ');
    write_single(h);
    write< true >(t...);
  }

  template< class... T >
  void writeln(const T &... t) {
    write(t...);
    write_single('\n');
  }

  Printer(FILE *_fp) : fp(_fp) {}

  ~Printer() { flush(); }

private:
  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;

  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }

  void write_single(const char &val) {
    if(pos == SIZE) flush();
    line[pos++] = val;
  }

  template< class T, enable_if_t< is_integral< T >::value, int > = 0 >
  void write_single(T val) {
    if(pos > (1 << 15) - 50) flush();
    if(val == 0) {
      write_single('0');
      return;
    }
    if(val < 0) {
      write_single('-');
      val = -val;  // todo min
    }
    size_t len = 0;
    while(val) {
      small[len++] = char('0' + (val % 10));
      val /= 10;
    }
    reverse(small, small + len);
    memcpy(line + pos, small, len);
    pos += len;
  }

  void write_single(const string &s) {
    for(char c : s) write_single(c);
  }

  void write_single(const char *s) {
    size_t len = strlen(s);
    for(size_t i = 0; i < len; i++) write_single(s[i]);
  }

  template< class T >
  void write_single(const vector< T > &val) {
    auto n = val.size();
    for(size_t i = 0; i < n; i++) {
      if(i) write_single(' ');
      write_single(val[i]);
    }
  }
};


// これがおれたちの動的木
// 動的木の時代の到来


struct Farthest {
  pi c_max, p_max;
  int64 length;

  Farthest() : c_max(pi(-infll, -1)), p_max(pi(-infll, -1)), length(0) {}

  void merge(int64 key, const Farthest &parent, const Farthest &child, const pi &t) {
    p_max = child.p_max;
    c_max = parent.c_max;
    if(key < 0) {
      chmax(p_max, pi(child.length, -key));
      chmax(c_max, pi(parent.length, -key));
      key = 0;
    }
    length = parent.length + key + child.length;
    chmax(p_max, pi(child.length + key + t.first, t.second));
    chmax(c_max, pi(parent.length + key + t.first, t.second));
    chmax(p_max, pi(child.length + key + parent.p_max.first, parent.p_max.second));
    chmax(c_max, pi(parent.length + key + child.c_max.first, child.c_max.second));
  }

  void toggle() {
    swap(c_max, p_max);
  }

  void add(const Farthest &child) {
  }

  void erase(const Farthest &child) {
  }
} e;

using LCT = LinkCutTreeSubtree< Farthest, int64, 600000 >;
LCT lct(e);
array< LCT::Node *, 200000 > ev, ee, getter;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int uku[200000];

int main() {
  Scanner in(stdin);
  Printer out(stdout);

  int N;
  in.read(N);

  for(int i = 0; i < N; i++) {
    ev[i] = lct.alloc(0);
  }

  for(int i = 0; i < N; i++) {
    getter[i] = lct.alloc(-(i + 1));
    lct.link(getter[i], ev[i]);
  }
  vector< int > A(N), B(N);
  WeightedGraph< int > g(N);
  for(int i = 1; i < N; i++) {
    int a, b, c;
    in.read(a, b, c);
    --a, --b;
    A[i] = a, B[i] = b;
    g[a].emplace_back(b, i);
    g[b].emplace_back(a, i);
    ee[i] = lct.alloc(c);
  }
  queue< int > que;
  que.emplace(0);
  vector< int > used(N);
  used[0] = true;
  while(!que.empty()) {
    int idx = que.front();
    que.pop();
    for(auto &to : g[idx]) {
      if(used[to]) continue;
      used[to] = true;
      que.emplace(to);
      lct.link(ev[to], ee[to.cost]);
      lct.link(ee[to.cost], ev[idx]);
    }
  }

  int Q;
  in.read(Q);
  int pre = 0;
  // えっ普通に戻してsplayすればいいのかしょうもね～～

  for(int i = 0; i < Q; i++) {
    int t, x;
    in.read(t, x);
    if(t == 1) {
      --x;
      pre = x;
    } else if(t == 2) {
      lct.evert(ee[x]);
      lct.cut(ev[A[x]]);
      lct.cut(ev[B[x]]);
    } else {
      lct.evert(ev[B[x]]);
      lct.link(ev[B[x]], ee[x]);
      lct.link(ee[x], ev[A[x]]);
    }
    lct.evert(ev[pre]);

    int64 far = ev[pre]->sum.c_max.first;
    if(far == 0) {
      out.write(1);
      out.write(" ");
      out.writeln(ev[pre]->sum.c_max.second);
      continue;
    }

    int ptr = 0;
    while(far == ev[pre]->sum.c_max.first) {
      uku[ptr++] = ev[pre]->sum.c_max.second;
      lct.cut(getter[uku[ptr - 1] - 1]);
      lct.evert(ev[pre]);
    }
    sort(uku, uku + ptr);
    out.write(ptr);
    for(int k = 0; k < ptr; k++) {
      out.write(" ");
      out.write(uku[k]);
    }
    out.writeln();

    for(int k = 0; k < ptr; k++) {
      const int &p = uku[k];
      lct.link(getter[p - 1], ev[p - 1]);
    }

  }
}

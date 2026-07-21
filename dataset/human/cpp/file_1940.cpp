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

template< typename SUM, typename KEY >
struct LinkCutTreeSubtree {

  struct Node {
    Node *l, *r, *p;
    int belong;

    KEY key;
    SUM sum;

    bool rev;
    int sz;

    bool is_root() const {
      return !p || (p->l != this && p->r != this);
    }

    Node(const KEY &key, const SUM &sum) :
        key(key), sum(sum), rev(false), sz(1), belong(-1),
        l(nullptr), r(nullptr), p(nullptr) {}
  };

  struct Edge {
    Node *p, *q;

    Edge(Node *p, Node *q) : p(p), q(q) {}
  };

  const SUM ident;
  vector< Node * > control;

  LinkCutTreeSubtree(const SUM &ident) : ident(ident) {}

  Node *make_node(const KEY &key) {
    auto ret = new Node(key, ident);
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
    t->sz = 1;
    if(t->l) t->sz += t->l->sz;
    if(t->r) t->sz += t->r->sz;
    t->sum.merge(t->key, t->l ? t->l->sum : ident, t->r ? t->r->sum : ident);
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
    if(~t->belong) control[t->belong] = t;

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
        cur->r->belong = (int) control.size();
        control.emplace_back(cur->r);
        cur->sum.add(cur->r->sum, cur->r->belong);
      }
      cur->r = rp;
      if(cur->r) {
        cur->sum.erase(cur->r->sum, cur->r->belong);
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

template< typename T, typename Compare = less< T > >
struct PQ {
  priority_queue< T, vector< T >, Compare > que1, que2;

  PQ() = default;

  void push(T k) {
    que1.emplace(k);
  }

  void pop(T k) {
    que2.emplace(k);
  }

  inline void modify() {
    while(que2.size() && que2.top() == que1.top()) {
      que2.pop();
      que1.pop();
    }
  }

  bool empty() {
    modify();
    return que1.empty();
  }

  T top() {
    modify();
    return que1.top();
  }
};


int main() {

  struct Sum {
    int64 all, pdist, cdist, sz, mdist, msz;
    PQ< pair< int64, int > > pq;

    Sum() : all(0), pdist(0), cdist(0), sz(0), mdist(0), msz(0) {}

    void toggle() {
      swap(pdist, cdist);
    }

    void merge(int key, const Sum &parent, const Sum &child) {
      bool sw = false;
      if(key == -1) {
        key = 0;
        sw = true;
      }
      all = parent.all + key + child.all;
      pdist = parent.pdist + (key + child.all) * (parent.sz + sw + msz) + child.pdist + mdist;
      cdist = child.cdist + (key + parent.all) * (child.sz + sw + msz) + parent.cdist + mdist;
      sz = parent.sz + child.sz + msz + sw;
    }

    void add(const Sum &chsum, int id) {
      mdist += chsum.cdist;
      msz += chsum.sz;
      pq.push({chsum.sz, id});
    }

    void erase(const Sum &chsum, int id) {
      mdist -= chsum.cdist;
      msz -= chsum.sz;
      pq.pop({chsum.sz, id});
    }

  } e;

  int N;
  cin >> N;
  using LCT =  LinkCutTreeSubtree< Sum, int >;
  LCT lct(e);
  vector< LCT::Node * > vv(N), ee(N);
  for(int i = 0; i < N; i++) {
    vv[i] = lct.make_node(i == 0 ? -1 : 0);
  }
  for(int i = 1; i < N; i++) {
    int p, d;
    cin >> p >> d;
    --p;
    ee[i] = lct.make_node(d);
    lct.link(vv[i], ee[i]);
    lct.link(ee[i], vv[p]);
  }


  auto search = MFP([&](auto search, LCT::Node *t, int half, int pre) -> LCT::Node * {
    lct.push(t);
    int r = t->r ? t->r->sum.sz : 0;
    if(t->r && half <= pre + r) return search(t->r, half, pre);

    if(!t->sum.pq.empty()) {
      auto ret = t->sum.pq.top();
      if(half <= ret.first) return search(lct.control[ret.second], half, 0);
    }

    int cur = (t->key == -1) + t->sum.msz + r + pre;
    if(half <= cur) return t;

    return search(t->l, half, cur);
  });


  cout << 0 << "\n";
  for(int i = 1; i < N; i++) {
    lct.set_key(vv[i], -1);
    auto center = search(vv[i], i / 2 + 1, 0);
    lct.evert(center);
    cout << center->sum.cdist << "\n";
  }
}

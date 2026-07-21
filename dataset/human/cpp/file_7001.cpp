#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;
// const int mod = 998244353;

const int64 infll = (1LL << 62) - 1;
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

int main() {
  int N;
  cin >> N;
  vector< int > A(N), B(N);
  cin >> B >> A;


  vector< vector< int > > C(N + 1), D(N + 1);
  for(int i = 0; i < N; i++) {
    C[A[i]].emplace_back(i);
  }
  for(int i = 0; i < N; i++) {
    D[B[i]].emplace_back(i);
  }
  multiset< pair< int, int > > latte, malta;
  for(int i = 1; i <= N; i++) {
    latte.emplace(C[i].size(), i);
  }
  vector< int > ans(N);
  for(int i = 1; i <= N; i++) {
    if(latte.count({C[i].size(), i})) {
      latte.erase({C[i].size(), i});
    }
    for(auto &p : D[i]) {
      if(latte.size() && latte.rbegin()->first > 0) {
        int idx = latte.rbegin()->second;
        ans[p] = idx;
        C[idx].pop_back();
        latte.erase(*latte.rbegin());
        latte.emplace(C[idx].size(), idx);
      } else if(malta.size() && malta.rbegin()->first > 0) {
        int idx = malta.rbegin()->second;
        ans[p] = idx;
        C[idx].pop_back();
        malta.erase(*malta.rbegin());
        malta.emplace(C[idx].size(), idx);
      } else {
        cout << "No\n";
        exit(0);
      }
    }
    malta.emplace(C[i].size(), i);
  }
  cout << "Yes\n";
  cout << ans << "\n";
}

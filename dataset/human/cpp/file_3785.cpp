#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cstdio>
#include <bitset>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>
#include <stack>
#include <cmath>
#include <string>

using namespace std;

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define INF (1 << 30)
#define LLINF (1LL << 62)
#define DEBUG(...) debug(__LINE__, ":" __VA_ARGS__)

constexpr int MOD = 1000000007;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

inline int popcount(ll x) { return __builtin_popcountll(x); }
inline int div2num(ll x) { return __builtin_ctzll(x); }
inline bool bit(ll x, int b) { return (x >> b) & 1; }

template <class T>
string to_string(T s);
template <class S, class T>
string to_string(pair<S, T> p);
string to_string(string s) { return s; }
string to_string(const char s[]) { return to_string(string(s)); }

template <class T>
string to_string(T v) {
  if (v.empty()) return "{}";
  string ret = "{";
  for (auto x : v) ret += to_string(x) + ",";
  ret.back() = '}';
  return ret;
}

template <class S, class T>
string to_string(pair<S, T> p) {
  return "{" + to_string(p.first) + ":" + to_string(p.second) + "}";
}
void debug() { cerr << endl; }

template <class Head, class... Tail>
void debug(Head head, Tail... tail) {
  cerr << to_string(head) << " ";
  debug(tail...);
}

struct IO {
#ifdef _WIN32
  inline char getchar_unlocked() { return getchar(); }
  inline void putchar_unlocked(char c) { putchar(c); }
#endif
  std::string separator = " ";
  template <class T>
  inline void read(T& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c != '-' && (c < '0' || '9' < c));
    bool minus = 0;
    if (c == '-') {
      minus = 1;
      c = getchar_unlocked();
    }
    x = 0;
    while ('0' <= c && c <= '9') {
      x *= 10;
      x += c - '0';
      c = getchar_unlocked();
    }
    if (minus) x = -x;
  }
  inline void read(std::string& x) {
    char c;
    do {
      c = getchar_unlocked();
    } while (c == ' ' || c == '\n');
    x.clear();
    do {
      x += c;
      c = getchar_unlocked();
    } while (c != ' ' && c != '\n' && c != EOF);
  }
  template <class T>
  inline void read(std::vector<T>& v) {
    for (auto& x : v) read(x);
  }
  template <class S, class T>
  inline void read(std::pair<S, T>& p) {
    read(p.first);
    read(p.second);
  }
  template <class Head, class... Tail>
  inline void read(Head& head, Tail&... tail) {
    read(head);
    read(tail...);
  }
  template <class T>
  inline void write(T x) {
    char buf[32];
    int p = 0;
    if (x < 0) {
      x = -x;
      putchar_unlocked('-');
    }
    if (x == 0) putchar_unlocked('0');
    while (x > 0) {
      buf[p++] = (x % 10) + '0';
      x /= 10;
    }
    while (p) {
      putchar_unlocked(buf[--p]);
    }
  }
  inline void write(std::string x) {
    for (char c : x) putchar_unlocked(c);
  }
  inline void write(const char s[]) {
    for (int i = 0; s[i] != 0; ++i) putchar_unlocked(s[i]);
  }
  template <class T>
  inline void write(std::vector<T> v) {
    if (v.empty()) return;
    for (auto itr = v.begin(); itr + 1 != v.end(); ++itr) {
      write(*itr);
      write(separator);
    }
    write(v.back());
  }
  template <class Head, class... Tail>
  inline void write(Head head, Tail... tail) {
    write(head);
    write(separator);
    write(tail...);
  }
  template <class Head, class... Tail>
  inline void writeln(Head head, Tail... tail) {
    write(head, tail...);
    write("\n");
  }
  void set_separator(std::string s) { separator = s; }
} io;

struct Prime {
  int n;
  vector<int> table;
  vector<int> primes;
  Prime(int _n = 100000) {
    n = _n + 1;
    table.resize(n, -1);
    table[0] = 0;
    table[1] = -1;
    for (int i = 2; i * i < n; ++i) {
      if (table[i] == -1) {
        for (int j = i * i; j < n; j += i) {
          table[j] = i;
        }
      }
    }
  }
  void enumerate_primes() {
    primes.clear();
    for (int i = 2; i < n; ++i) {
      if (table[i] == -1) primes.push_back(i);
    }
  }
  vector<pair<long long, int>> prime_factor(long long x) {
    map<long long, int> mp;
    long long div = 2;
    int p = 0;
    while (n <= x && div * div <= x) {
      if (x % div == 0) {
        mp[div]++;
        x /= div;
      } else {
        if (p + 1 < primes.size()) {
          div = primes[++p];
        } else {
          div++;
        }
      }
    }
    if (x < n) {
      while (table[x] != -1) {
        mp[table[x]]++;
        x /= table[x];
      }
    }
    if (x > 1) mp[x]++;
    vector<pair<long long, int>> ret;
    for (auto p : mp) ret.push_back(p);
    return ret;
  }
};

template <int MOD = 1000000007>
struct Math {
  vector<long long> fact, factinv, inv;
  Math(int n = 100000) {
    fact.resize(n + 1);
    factinv.resize(n + 1);
    inv.resize(n + 1);
    fact[0] = fact[1] = 1;
    factinv[0] = factinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fact[i] = fact[i - 1] * i % MOD;
      inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
      factinv[i] = factinv[i - 1] * inv[i] % MOD;
    }
  }
  long long C(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * (factinv[r] * factinv[n - r] % MOD) % MOD;
    }
  }
  long long P(int n, int r) {
    if (n < r || n < 0 || r < 0) {
      return 0;
    } else {
      return fact[n] * factinv[n - r] % MOD;
    }
  }
  long long H(int n, int r) { return C(n + r - 1, r); }
};

struct UnionFind {
  vector<int> data;
  vector<vector<int>> groups;
  UnionFind(int n) : data(n, -1) {}
  int root(int v) { return data[v] < 0 ? v : data[v] = root(data[v]); }
  bool unite(int u, int v) {
    if ((u = root(u)) == (v = root(v))) {
      return 1;
    } else {
      if (-data[u] < -data[v]) swap(u, v);
      data[u] += data[v];
      data[v] = u;
      return 0;
    }
  }
  int size(int v) { return -data[root(v)]; }
  void make_groups() {
    map<int, vector<int>> mp;
    for (int i = 0; i < data.size(); ++i) mp[root(i)].push_back(i);
    groups.clear();
    for (auto p : mp) groups.push_back(p.second);
  }
};

namespace phc {
long long modpow(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % MOD;
    a = a * a % MOD;
    n >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) { return b != 0 ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
}  // namespace phc

int main() {
  double xs, ys, xt, yt;
  int N;
  cin >> xs >> ys >> xt >> yt >> N;
  using tp = tuple<double, double, double>;
  vector<tp> bars(N + 2);
  bars[0] = tp(xs, ys, 0);
  bars[N + 1] = tp(xt, yt, 0);
  FOR(i, 1, N + 1)
  cin >> (get<0>(bars[i])) >> (get<1>(bars[i])) >> (get<2>(bars[i]));
  vector<double> dists(N + 2, LLINF);
  using tp2 = pair<double, int>;
  priority_queue<tp2, vector<tp2>, greater<tp2>> q;
  q.push(tp2(0, 0));
  auto getd = [&](int u, int v) {
    double x = abs(get<0>(bars[u]) - get<0>(bars[v])),
           y = abs(get<1>(bars[u]) - get<1>(bars[v]));
    return max(0.0, sqrt(x * x + y * y) - get<2>(bars[u]) - get<2>(bars[v]));
  };
  while (!q.empty()) {
    double d = q.top().first;
    int v = q.top().second;
    q.pop();
    if (dists[v] <= d) continue;
    dists[v] = d;
    REP(i, N + 2) {
      if (dists[i] > d + getd(v, i)) {
        q.push(tp2(d + getd(v, i), i));
      }
    }
  }
  printf("%.10f\n", dists[N + 1]);
  return 0;
}

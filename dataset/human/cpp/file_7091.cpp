#include <bits/stdc++.h>

#include <boost/hana/functional/fix.hpp>

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_pair : std::false_type {};
template <typename T>
struct is_pair<T, std::void_t<decltype(std::declval<T>().first),
                              decltype(std::declval<T>().second)>>
    : std::true_type {};

template <typename T>
void debug(const T& v) {
  if constexpr (is_pair<T>::value) {
    std::cerr << "{";
    debug(v.first);
    std::cerr << ", ";
    debug(v.second);
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);
#define ints(...) rd(int, __VA_ARGS__);
#define strings(...) rd(string, __VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? "Yes" : "No");
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  write_to_cout(value);
  std::cout << ' ';
  write_to_cout(args...);
}
#define wt(...)                 \
  do {                          \
    write_to_cout(__VA_ARGS__); \
    cout << '\n';               \
  } while (0)

#define all(x) (x).begin(), (x).end()

#define rep_dispatch(_1, _2, _3, name, ...) name

#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) rep_dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep3(i, a, b) for (int i = (int)(b)-1; i >= a; --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep2(_loop_variable_, n)
#define rrep(...) rep_dispatch(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
T max(T a, U b) {
  return a > b ? a : b;
}

template <typename T, typename U>
T mix(T a, U b) {
  return a < b ? a : b;
}

template <typename T>
int sz(const T& v) {
  return v.size();
}

template <typename T>
int popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

using i64 = std::int64_t;
using i32 = std::int32_t;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

void Main();

int main() {
  Main();
  return 0;
}

const auto& Fix = boost::hana::fix;

using namespace std;

#define int i64

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  map<int, int> ac, bc, tot;
  rep(i, n) {
    ac[a[i]]++;
    bc[b[i]]++;
    tot[a[i]]++;
    tot[b[i]]++;
  }

  for (auto [_, v] : tot) {
    if (v > n) {
      wt("No");
      return;
    }
  }

  multiset<pair<int, int>, greater<>> rac, rbc, rem;
  for (auto [x, c] : ac) rac.insert({c, x});
  for (auto [x, c] : bc) {
    if (ac.count(x)) {
      rbc.insert({c, x});
    } else {
      rem.insert({c, x});
    }
  }

  V<pair<int, int>> ans;
  for (auto ait = rac.begin(); ait != rac.end(); ++ait) {
    // x is the most frequent element in A.
    auto [c, x] = *ait;
    rep(ci, c) {
      // it points to the most frequent element in B, excluding x.
      auto it = rbc.begin();
      while (it != rbc.end() && it->second == x) {
        auto jt = it;
        ++it;
        rem.insert(*jt);
        rbc.erase(jt);
      }
      if (it == rbc.end()) {
        // Fill ra and rb with the remaining elements from A and B,
        // respectively.
        V<int> ra;
        rep(c - ci) ra.push_back(x);
        for (++ait; ait != rac.end(); ++ait) {
          rep(ait->first) ra.push_back(ait->second);
        }
        V<int> rb;
        for (auto [c, x] : rem) rep(c) rb.push_back(x);
        assert(sz(ra) == sz(rb));

        // Elements from ra and rb are different, except for the remaining x
        // (from the last loop). So rotate rb so that there's no collision.
        if (c > ci) {
          int j = -1;
          rep(i, sz(rb)) if (rb[i] == x) {
            j = i;
            break;
          }
          int rot = (c - ci) - j;
          int m = sz(rb);
          V<int> rc(m);
          rep(i, m) rc[(i + rot + m) % m] = rb[i];
          swap(rc, rb);
        }

        rep(i, sz(ra)) ans.push_back({ra[i], rb[i]});
        goto out;
      }
      // Pair x and y, then continue.
      auto [d, y] = *it;
      rbc.erase(it);
      ans.push_back({x, y});
      if (d > 1) rbc.insert({d - 1, y});
    }
  }

out:
  rep(i, n) assert(ans[i].first != ans[i].second);

  wt("Yes");
  sort(all(ans));
  rep(i, n) {
    if (i) cout << " ";
    cout << ans[i].second;
  }
  cout << endl;
}

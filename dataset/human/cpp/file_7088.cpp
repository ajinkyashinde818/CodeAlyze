#include <bits/stdc++.h>

// #include <atcoder/all>

#include <boost/concept_check.hpp>
#include <functional>
#include <vector>

template <
    typename T,
    typename F,
    typename LazyT = T,
    typename LazyApply = T (*)(const T&, const LazyT&, int, int),
    typename LazyAdd = LazyT (*)(const LazyT&, const LazyT&)>
class segtree {
  BOOST_CLASS_REQUIRE2(F, std::function<T(T&, T&)>, boost, ConvertibleConcept);
  BOOST_CLASS_REQUIRE2(LazyApply, std::function<T(T&, LazyT&, int, int)>, boost, ConvertibleConcept);
  BOOST_CLASS_REQUIRE2(LazyAdd, std::function<LazyT(LazyT&, LazyT&)>, boost, ConvertibleConcept);

  const F f;
  const LazyApply lazyApply;
  const LazyAdd lazyAdd;

  std::vector<T> data;
  std::vector<LazyT> lazyData;
  std::vector<bool> lazyflag;

  inline int dataLength(int n) {
    int res = 2;
    while (res < n) res = res << 1;
    return res;
  }

  inline void recalcData(int p, int pBegin, int pEnd) {
    data[p] = f(data[(p << 1) + 1], data[(p << 1) + 2]);
    if (lazyflag[p]) data[p] = lazyApply(data[p], lazyData[p], pBegin, pEnd);
  }

  void _updateLazy(int begin, int end, const LazyT& value, int p, int pBegin, int pEnd) {
    if (begin <= pBegin && pEnd <= end) {
      addLazyData(p, pBegin, pEnd, value);
    } else if (pBegin < end && begin < pEnd) {
      evalLazy(p, pBegin, pEnd);
      int pCenter = (pBegin + pEnd) >> 1;
      _updateLazy(begin, end, value, (p << 1) + 1, pBegin, pCenter);
      _updateLazy(begin, end, value, (p << 1) + 2, pCenter, pEnd);
      recalcData(p, pBegin, pEnd);
    }
  }

  inline void addLazyData(int p, int pBegin, int pEnd, const LazyT& value) {
    data[p] = lazyApply(data[p], value, pBegin, pEnd);
    lazyData[p] = lazyflag[p]
                      ? lazyAdd(lazyData[p], value)
                      : value;
    lazyflag[p] = true;
  }

  inline void evalLazy(int p, int pBegin, int pEnd) {
    if (!lazyflag[p]) return;
    int pCenter = (pBegin + pEnd) >> 1;
    addLazyData((p << 1) + 1, pBegin, pCenter, lazyData[p]);
    addLazyData((p << 1) + 2, pCenter, pEnd, lazyData[p]);
    lazyflag[p] = false;
  }

  T _calc(int begin, int end, int p, int pBegin, int pEnd) {
    if (begin <= pBegin && pEnd <= end) {
      return data[p];
    } else if (end <= pBegin || pEnd <= begin) {
      return fIdentity;
    } else {
      evalLazy(p, pBegin, pEnd);
      int pCenter = (pBegin + pEnd) >> 1;
      return f(
          _calc(begin, end, (p << 1) + 1, pBegin, pCenter),
          _calc(begin, end, (p << 1) + 2, pCenter, pEnd));
    }
  }

 public:
  const int rawN;
  const int n;
  const T fIdentity;

  template <typename N, typename std::enable_if<std::is_convertible<N, int>::value, std::nullptr_t>::type _cnd = nullptr>
  segtree(
      N n,
      F f,
      T fIdentity,
      LazyApply lazyApply = nullptr,
      LazyAdd lazyAdd = nullptr,
      LazyT _someValueOfLazyT = LazyT() /* for deduction of LazyT */)
      : rawN(n),
        n(dataLength(n)),
        f(f),
        fIdentity(fIdentity),
        lazyApply(lazyApply),
        lazyAdd(lazyAdd) {
    data.resize(2 * this->n - 1);
    lazyData.resize(2 * this->n - 1);
    lazyflag.resize(2 * this->n - 1);
    for (int i = 0; i < 2 * this->n - 1; ++i) data[i] = fIdentity;
  }

  template <typename Iterable, typename std::enable_if<!std::is_convertible<Iterable, int>::value, std::nullptr_t>::type _cnd = nullptr>
  segtree(
      Iterable iterable,
      F f,
      T fIdentity,
      LazyApply lazyApply = nullptr,
      LazyAdd lazyAdd = nullptr,
      LazyT _someValueOfLazyT = LazyT())
      : segtree(std::size(iterable), f, fIdentity, lazyApply, lazyAdd) {
    int i = 0;
    for (auto&& x : iterable) data[n - 1 + i++] = x;
    for (int p = n - 2; p >= 0; --p) data[p] = f(data[(p << 1) + 1], data[(p << 1) + 2]);
  }

  template <typename BuildFunc>
  void build(BuildFunc buildFunc) {
    for (int i = 0; i < rawN; ++i) data[n - 1 + i] = buildFunc(i);
    for (int p = n - 2; p >= 0; --p) data[p] = f(data[(p << 1) + 1], data[(p << 1) + 2]);
  }

  void update(int index, const T& value) {
    int p = n + index - 1, pBegin = index, pSize = 1;
    data[p] = value;
    while (p > 0) {
      if ((p & 1) == 0) pBegin -= pSize;
      p = (p - 1) >> 1;
      pSize <<= 1;
      recalcData(p, pBegin, pBegin + pSize);
    }
  }

  void updateLazy(int begin, int end, const LazyT& value) {
    _updateLazy(begin, end, value, 0, 0, n);
  }

  T operator()(int begin, int end) {
    return _calc(begin, end, 0, 0, n);
  }
};

// #LIB#

using namespace std;
// using namespace atcoder;
using ll = long long;
#define double long double
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#ifdef ONLINE_JUDGE
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');
#endif

random_device _rnd = random_device();
double rnd() {
  return (double)_rnd() / UINT32_MAX;
}

const string Yes = "Yes";
const string No = "No";
int main() {
  auto t0 = clock();
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> b(n);
  rep(i, n) cin >> b[i];
  vector<pair<ll, ll>> b_ng(n);
  rep(i, n) {
    b_ng[i].first = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
    b_ng[i].second = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
  }
  const ll INF = LLONG_MAX / 4;
  auto f_min = [](const ll& a, const ll& b) { return min(a, b); };
  auto f_max = [](const ll& a, const ll& b) { return max(a, b); };
  segtree tl(n, f_min, INF);
  segtree tr(n, f_max, -INF);
  vector<ll> ans(n, LLONG_MIN);
  while (ans[0] == LLONG_MIN && clock() - t0 < 1.8 * CLOCKS_PER_SEC) {
    tl.build([](const int& i) { return i; });
    tr.build([](const int& i) { return i; });
    rep(i, n) {
      ll p;
      if (rnd() < 0.5) {
        p = tl(b_ng[i].second, n);
      } else {
        p = tr(b_ng[i].second, n);
      }
      if (!(0 <= p && p < n)) p = tl(0, b_ng[i].first);
      if (0 <= p && p < n) {
        ans[p] = b[i];
        tl.update(p, tl.fIdentity);
        tr.update(p, tr.fIdentity);
      } else {
        ans[0] = LLONG_MIN;
        break;
      }
    }
  }
  if (ans[0] == LLONG_MIN) {
    cout << No << endl;
  } else {
    cout << Yes << endl;
    rep(i, n) {
      cout << ans[i];
      if (i + 1 < n) cout << ' ';
    }
    cout << endl;
  }
}

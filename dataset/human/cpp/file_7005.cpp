#include <bits/extc++.h>

struct random : std::mt19937 {
  using std::mt19937::mt19937;
  using std::mt19937::operator();

  static int64_t gen_seed() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
  }

  random() : std::mt19937(gen_seed()) {}

  template <class Int>
  auto operator()(Int a, Int b)
      -> std::enable_if_t<std::is_integral_v<Int>, Int> {
    return std::uniform_int_distribution<Int>(a, b)(*this);
  }
  template <class Real>
  auto operator()(Real a, Real b)
      -> std::enable_if_t<std::is_floating_point_v<Real>, Real> {
    return std::uniform_real_distribution<Real>(a, b)(*this);
  }
} rng;

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), b(n), ca(n + 1), cb(n + 1);
  for (auto&& e : a) cin >> e, ++ca[e];
  for (auto&& e : b) cin >> e, ++cb[e];
  for (int x = 1; x <= n; ++x)
    if (ca[x] + cb[x] > n) {
      cout << "No\n";
      exit(0);
    }
  cout << "Yes\n";
  vector<int> order(n);
  iota(begin(order), end(order), 1);
  sort(begin(order), end(order),
       [&](int x, int y) { return ca[x] + cb[x] > ca[y] + cb[y]; });
  vector<int> res(n);
  auto comp = [&](int i, int j) {
    int x = a[i], y = a[j];
    return pair{ca[x] + cb[x], -i} > pair{ca[y] + cb[y], -j};
  };
  vector<vector<int>> idx(n + 1);
  for (int i = 0; i < n; ++i) idx[a[i]].push_back(i);
  while (true) {
    int y = -1;
    [&] {
      set<int, decltype(comp)> se(comp);
      for (int i = 0; i < n; ++i) se.insert(i);
      for (int x : order) {
        vector<int> erased;
        for (int i : idx[x])
          if (se.count(i)) {
            se.erase(i);
            erased.push_back(i);
          }
        for (int _ = cb[x]; _--;) {
          if (empty(se)) {
            y = x;
            return;
          }
          auto it = begin(se);
          res[*it] = x;
          se.erase(it);
        }
        for (int i : erased) se.insert(i);
      }
      for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i == n - 1];
      exit(0);
    }();
    shuffle(begin(order), end(order), rng);
    // swap(order.front(), *find(begin(order), end(order), y));
  }
}

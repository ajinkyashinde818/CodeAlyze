#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  struct node_t {
    bool is_a;
    int index;
    int key;

    bool operator<(const node_t& r) const { return key < r.key; }
  };

  std::vector<node_t> a(n), b(n);
  for (int i = 0; i != n; ++i) {
    a[i].is_a = true;
    a[i].index = i;
    std::cin >> a[i].key;
  }
  for (int i = 0; i != n; ++i) {
    b[i].is_a = false;
    b[i].index = i;
    std::cin >> b[i].key;
  }
  std::vector<node_t> c(2 * n);
  std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());

  std::vector<int> rem;
  for (int i = 0; i != n; ++i) {
    auto& x = c[i];
    auto& y = c[n + i];
    if (x.key == y.key) {
      std::cout << "No\n";
      return 0;
    }
    if (x.is_a != y.is_a) {
      continue;
    }
    if (rem.empty() || c[rem.back()].is_a == x.is_a) {
      rem.push_back(i);
      continue;
    }
    auto& s = c[rem.back()];
    auto& t = c[n + rem.back()];
    rem.pop_back();
    std::swap(s, x);
    if (s.key == t.key || x.key == y.key) {
      std::swap(s, y);
    }
  }
  std::vector<int> ans(n);
  for (int i = 0; i != n; ++i) {
    auto& x = c[i];
    auto& y = c[n + i];
    if (!x.is_a) {
      std::swap(x, y);
    }
    ans[x.index] = y.key;
  }

  std::cout << "Yes\n";
  for (int e : ans) {
    std::cout << e << " ";
  }

  return 0;
}

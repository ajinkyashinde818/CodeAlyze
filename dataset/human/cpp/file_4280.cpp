#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;


int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  int x = 0;
  vector <int> a(n);
  multiset <int> have;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    x ^= a[i];
    have.insert(a[i]);
  }
  have.insert(x);
  vector <int> c(have.begin(), have.end());
  c.resize(unique(c.begin(), c.end()) - c.begin());
  vector <int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) {
    if (have.find(b[i]) == have.end()) {
      cout << "-1\n";
      return 0;
    }
    have.erase(have.find(b[i]));
  }
  auto get = [&] (int id) {
    return lower_bound(c.begin(), c.end(), id) - c.begin();
  };
  int k = c.size();
  vector <vector <int>> g(k);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      g[get(a[i])].push_back(get(b[i]));
      g[get(b[i])].push_back(get(a[i]));
      ++ans;
    }
  }
  vector <int> used(k);
  for (int i = 0; i < k; ++i) {
    if (!used[i] && g[i].size() > 0) {
      ++ans;
      queue <int> q;
      q.push(i);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
          if (!used[v]) {
            used[v] = 1;
            q.push(v);
          }
        }
      }
    }
  }   
  if (g[get(x)].size() > 0) --ans; 
  cout << ans << '\n';
}

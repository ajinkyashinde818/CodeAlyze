#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, a[N], b[N], fa[N], fb[N], st[N], en[N], ans[N];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    ++fa[a[i]];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", b + i);
    ++fb[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (fa[i] + fb[i] > n) {
      puts("No");
      return 0;
    }
  }
  puts("Yes");
  for (int i = 1; i <= n; ++i) {
    st[i] = n + 69, en[i] = -69;
  }
  for (int i = 1; i <= n;) {
    int x = a[i];
    st[x] = i;
    while (i <= n and a[i] == x) ++i;
    en[x] = i - 1;
  }
  set <int> alive;
  for (int i = 1; i <= n; ++i) {
    alive.emplace(i);
  }
  int badValue = -1;
  vector <pair <int, int>> done;
  for (int i = 1; i <= n; ++i) {
    if (!fb[i]) continue;
    while (fb[i] > 0) {
      if (*alive.begin() < st[i]) {
        int at = *alive.begin();
        alive.erase(alive.begin());
        ans[at] = i;
        done.emplace_back(at, i);
      } else {
        auto it = alive.upper_bound(en[i]);
        if (it == alive.end()) {
          badValue = i;
          break;
        } else { 
          int at = *it;
          alive.erase(at);
          ans[at] = i;
          done.emplace_back(at, i);
        }
      }
      --fb[i];
    }
  }
  if (~badValue) {
    for (auto it : done) {
      if (alive.empty()) break;
      if (a[it.first] != badValue and it.second != badValue) {
        int at = *alive.begin(); 
        alive.erase(alive.begin());
        ans[it.first] = badValue;
        ans[at] = it.second;
      }
    }
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  cout << '\n';
  return 0;
}

// 1 1 1 2 2 4 5
// 1 1 1 2 6 7 8
// 6 7 8 1 1 1 2
// 1 1 1 2 6 7 8

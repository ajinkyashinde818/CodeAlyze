#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int a[N], b[N], c[N], d[N];
map <int, int> p;

inline int find_set(int x) {
  if (p.find(x) == p.end()) {
    p[x] = x;
    return x;
  }
  if (x != p[x]) {
    p[x] = find_set(p[x]);
  }
  return p[x];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  a[n] = b[n] = 0;
  for (int i = 0; i < n; i++) {
    a[n] ^= a[i];
    b[n] ^= b[i];
  }
  n++;
  {
    for (int i = 0; i < n; i++) {
      c[i] = a[i];
      d[i] = b[i];
    }
    sort(c, c + n);
    sort(d, d + n);
    for (int i = 0; i < n; i++) {
      if (c[i] != d[i]) {
        printf("%d\n", -1);
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += (a[i] != b[i]);
  }           
  if (ans == 0) {
    printf("%d\n", 0);
    return 0;
  }
  vector < pair <int, int> > e;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i] || i == n - 1) {
      e.emplace_back(a[i], b[i]);
    }
  }
  p.clear();
  for (int i = 0; i < (int) e.size(); i++) {
    int x = e[i].first;
    int y = e[i].second;
    int xx = find_set(x);
    int yy = find_set(y);
    if (xx != yy) {
      p[xx] = yy;
    }
  }
  set <int> all;
  for (auto &z : p) {
    all.insert(find_set(z.first));
  }
  ans += (int) all.size();
  ans--;
  printf("%d\n", ans);
  return 0;
}

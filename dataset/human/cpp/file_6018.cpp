#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

namespace Header_Template {
  typedef long long li;
  template<class T>inline void read(T &x) {
    x = 0;
    T tmp = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') tmp = -1, c = getchar();
    while (c >= '0' && c <= '9')
      x = (x << 1) + (x << 3) + c - '0', c = getchar();
    x *= tmp;
  }
  template<class T>inline void Max(T &x, T y) {
    if (y > x) x = y;
  }
  template<class T>inline void Min(T &x, T y) {
    if (y < x) x = y;
  }
}
using namespace Header_Template;

const int N = 1e5 + 10;
int n;
li c, v[N], x[N], s[N];
li a[N], b[N];
multiset<li> S;

int main(void) {
  read(n), read(c);
  for (int i = 1; i <= n; ++i)
    read(x[i]), read(v[i]);
  s[0] = 0;
  for (int i = 1; i <= n; ++i)
    s[i] = s[i - 1] + v[i];

  li ans = 0;
  for (int i = 1; i <= n; ++i) {
    a[i] = s[i] - x[i];
    b[i] = s[n] - s[i - 1] - (c - x[i]);
    Max(ans, max(a[i], b[i]));
  }
  for (int i = 1; i <= n; ++i) S.insert(b[i]);
  for (int i = 1; i <= n; ++i) {
    S.erase(S.find(b[i]));
    if (S.size()) Max(ans, a[i] - x[i] + *--S.end());
  }
  S.clear();
  for (int i = 1; i <= n; ++i) S.insert(a[i]);
  for (int i = n; i; --i) {
    S.erase(S.find(a[i]));
    if (S.size()) Max(ans, b[i] - (c - x[i]) + *--S.end());
  }
  printf("%lld\n", ans);

  return 0;
}

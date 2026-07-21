#include <set>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100005;

int n, sa, sb, ans;
int a[N], b[N], v[N];
int f[N], si[N];
vector<int> va, vb;

inline int Num(int x) {
  return lower_bound(v + 1, v + 1 + *v, x) - v;
}
int Sk(int x) {
  return f[x] == x? x : f[x] = Sk(f[x]);
}
void Mr(int x, int y) {
  x = Sk(x), y = Sk(y);
  if (x != y) f[x] = y, si[y] += si[x];
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sa ^= (v[i] = a[i]);
    va.push_back(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
    sb ^= b[i];
    vb.push_back(b[i]);
  }
  va.push_back(sa), vb.push_back(sb);
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  if (va != vb) {
    puts("-1");
    return 0;
  }
  v[(*v) = n + 1] = sa;
  sort(v + 1, v + 1 + *v);
  *v = unique(v + 1, v + 1 + *v) - v - 1;
  for (int i = 1; i <= *v; ++i)
    f[i] = i;
  int rt = Num(sa), idx = -1;
  for (int i = 1; i <= n; ++i)
    a[i] = Num(a[i]);
  for (int i = 1; i <= n; ++i) {
    b[i] = Num(b[i]);
    if (a[i] != b[i]) ++si[b[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == b[i]) continue;
    if (b[i] == rt) idx = i;
    Mr(a[i], b[i]);
  }
  if (idx != -1) --ans;
  for (int i = 1; i <= *v; ++i)
    if (Sk(i) == i && si[i] > 0) ans += si[i] + 1;
  printf("%d\n", ans);
  return 0;
}

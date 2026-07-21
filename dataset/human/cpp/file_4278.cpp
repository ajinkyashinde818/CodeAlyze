#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
const int MAXN = 100000 + 10;

int n;
int a[MAXN], b[MAXN];
namespace solver1 {

  int fa[MAXN];
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void main() {
    static int seq1[MAXN], seq2[MAXN];
    for (int i = 1; i <= n; i++) {
      a[n + 1] ^= a[i];
      seq1[i] = a[i];
    }
    seq1[n + 1] = a[n + 1];

    for (int i = 1; i <= n; i++) {
      b[n + 1] ^= b[i];
      seq2[i] = b[i];
    }
    seq2[n + 1] = b[n + 1];
    std::sort(seq1 + 1, seq1 + n + 2);
    std::sort(seq2 + 1, seq2 + n + 2);
    for (int i = 1; i <= n + 1; i++) {
      if (seq1[i] != seq2[i]) {
        puts("-1");
        return;
      }
    }

    for (int i = 1; i <= n + 1; i++) fa[i] = i;

    std::map<int, int> last1, last2;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] == b[i]) continue;
      if (last1.count(a[i])) {
        fa[find(last1[a[i]])] = find(i);
      }

      if (last1.count(b[i])) {
        fa[find(last1[b[i]])] = find(i);
      }

      if (last2.count(a[i])) {
        fa[find(last2[a[i]])] = find(i);
      }
      
      if (last2.count(b[i])) {
        fa[find(last2[b[i]])] = find(i);
      }
      last1[a[i]] = i;
      last2[b[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (a[i] == b[i]) continue;

      ans += 1 + (fa[i] == i);
    }
    if (a[n + 1] == b[n + 1]) {
      if (last1.count(a[n + 1])) {
        printf("%d\n", ans - 1);
      } else {
        printf("%d\n", ans);
      }
    } else {
      printf("%d\n", ans - 2);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }

  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }

  solver1::main();
  
}

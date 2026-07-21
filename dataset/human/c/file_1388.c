#include <stdio.h>
#include <stdlib.h>

int a[200000], b[200000], ac, bc, aa[200000], bb[200000];

int solve() {
  for(int i = 0; i < 200000; i++) {
    if(aa[i] == 1 && 1 == bb[i]) return 1;
  }
  return 0;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < m; i++) {
    int _a, _b; scanf("%d %d", &_a, &_b);
    if(_a == 1) {
      aa[_b] = 1;
    } else if(_b == n) {
      bb[_a] = 1;
    }
  }
  puts(solve() ? "POSSIBLE" : "IMPOSSIBLE");
}

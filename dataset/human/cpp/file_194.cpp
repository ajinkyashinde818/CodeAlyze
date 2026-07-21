#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b, n;
  scanf("%d%d%d%d", &r, &g, &b, &n);
  int cnt = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int k = n - i - j;
      if (k < 0) break;
      if (i % r == 0 and j % g == 0 and k % b == 0) cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}

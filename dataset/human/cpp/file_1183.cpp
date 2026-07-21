// [[ABC134C] Exception Handling] https://www.luogu.com.cn/problem/AT4843
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main() {
  int r, g, b, n;
  scanf("%d%d%d%d", &r, &g, &b, &n);

  int ans = 0;
  for (int i = 0; i <= 3000; i++) {
    for (int j = 0; j <= 3000; j++) {
      int t = i * r + j * g;
      if (n >= t && (n - t) % b == 0) ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}

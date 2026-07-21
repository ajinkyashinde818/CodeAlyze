#include <stdio.h>

int main()
{
  int i, n, m, a;
  char broken[100001];
  long ans[100001];
  scanf("%d%d", &n, &m);
  for (i = 0; i <= n; i++) broken[i] = 0;
  for (i = 0; i < m; i++) {
    scanf("%d", &a);
    broken[a] = 1;
  }
  if (n == 1) {
    printf("%d\n", 1);
    return 0;
  }
  ans[0] = 1;
  if (broken[1]) ans[1] = 0; else ans[1] = 1;
  for (i = 2; i <= n; i++) {
    if (broken[i]) ans[i] = 0;
    else ans[i] = (ans[i - 2] + ans[i - 1]) % 1000000007;
  }
  printf("%d\n", ans[n]);
  return 0;
}

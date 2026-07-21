#include <stdio.h>

int main(void) {
  int n, i; //n = ゲームを行う回数
  scanf("%d", &n);
  int k[n], p[n], res[n]; //k = 石の数, p = 人数, res =　勝者
  for (i = 0; i < n; i++) {
    scanf("%d%d", &k[i], &p[i]);
    res[i] = k[i] % p[i];
    if (res[i] == 0) {
      res[i] = p[i];
    }
  }
  for (i = 0; i < n; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}

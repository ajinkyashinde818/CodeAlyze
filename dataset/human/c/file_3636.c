/*
 * C言語のサンプルプログラム - Webkaru
 * - 入力した2つの自然数の最小公倍数を求める -
 */
#include <stdio.h>

int main(void)
{

  long a, b, r, x, tmp;

  scanf("%ld", &a);
  scanf("%ld", &b);

  x = a * b;

  /* 自然数 a > b を確認・入替 */
  if (a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }

  /* ユークリッドの互除法 */
  r = a % b;
  while (r != 0) {
    a = b;
    b = r;
    r = a % b;
  }

  /* 最小公倍数を出力 */
  printf("%ld", x / b);

  return 0;
}

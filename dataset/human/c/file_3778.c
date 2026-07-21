#include <stdio.h>

int main(void)
{

  long long int a, b, r, x, tmp;


  scanf("%lld", &a);

  scanf("%lld", &b);

  x = a * b;

  /* 自然数 a > b を確認・入替 */
  if(a<b){
    tmp = a;
    a = b;
    b = tmp;
  }

  /* ユークリッドの互除法 */
  r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }

  /* 最小公倍数を出力 */
  printf("%lld\n", x/b);

  return 0;
}

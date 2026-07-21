#include <stdio.h>

int main(void)
{
  int k, s, x, y, z, num = 0;

  /*入力*/
  scanf("%d %d", &k, &s);

  /*処理*/
  for (x=0;x<=k;x++) {
    for (y=x;y<=k;y++) {
      for (z=y;z<=k;z++) {
        if (x + y + z == s) {
          if(x == y && y == z) {
            num++;
            break;
          } else if (x == y || x == z || y == z) {
            num = num + 3;
            break;
          } else {
            num = num + 6;
            break;
          }
        }
      }
    }
  }

  /*出力*/
  printf("%d\n", num);
  return 0;
}

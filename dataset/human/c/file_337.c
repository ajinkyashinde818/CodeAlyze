#include <stdio.h>  /*入出力*/
#include <stdlib.h> /*標準ライブラリ*/
#include <string.h> /*文字列*/
#include <math.h>   /*計算*/
#include <assert.h> /*確認*/
#include <ctype.h>  /*文字操作*/
#include <stdbool.h>/*bool型の利用*/

//abc156-1
//date 03/05

int main(void)
{
  int N;
  int R;
  scanf("%d %d", &N, &R);

  if (N < 10) {
    R += 100 * (10 - N);
  }

  printf("%d\n", R);
  return 0;
}

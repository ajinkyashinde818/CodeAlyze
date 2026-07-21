#include <stdio.h>  /*入出力*/
#include <stdlib.h> /*標準ライブラリ*/
#include <string.h> /*文字列*/
#include <math.h>   /*計算*/

/*ABC 142*/

int main(void)
{
  int N, K;
  int count = 0;
  int *array;

  scanf("%d%d", &N, &K);
  array = (int *)malloc(sizeof(int) * N);
  if (array == NULL) {
    exit(0);
  }

  for (size_t i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }

  for (size_t i = 0; i < N; i++) {
    if (array[i] >= K) {
      count++;
    }
  }
  printf("%d\n", count);
  free(array);
  return 0;
}

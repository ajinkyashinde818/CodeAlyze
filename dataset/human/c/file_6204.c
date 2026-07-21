// ALDS1_1_D	Maximum profit
// 2018.3.20

#include <stdio.h>

int main (void){

  int i, n, max, min, R;
  max = 1 - 1000000000;

  scanf("%d\n", &n);
  scanf("%d\n", &min);

  for(i = 2; i <= n; i++)
    {
      scanf("%d\n", &R);
      if(max < R - min){ max = R - min;}
      if(min > R){ min = R;}
    }
  printf("%d\n", max);
  return 0;
}

/*
  ある通貨について、時刻 t における価格 Rt (t=0,1,2,,,n−1)が入力として与えられ、その価格の差 Rj−Ri (ただし、j>i とする) の最大値を求めるプログラム
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, n, num, max, min;

  scanf("%d%d", &n, &num);

  min = num;
  for( i = 1; i<n; i++ )
    {
      scanf("%d", &num);
      if( i == 1 )
	max = num - min;
      if( max < num - min )
	max = num - min;
      if( min > num )
	min = num;
    }
  
  printf("%d\n", max);

  return 0;
}

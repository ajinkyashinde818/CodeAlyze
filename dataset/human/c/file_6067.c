#include <stdio.h>

#define N 200000

int main()
{
  int i, num, maxnum, minnum, array[N];

  scanf("%d", &num);

  for( i=0; i<num; i++){
    scanf("%d", &array[i]);
  }

  maxnum = array[1] - array[0];
  minnum = array[0];
  
  for( i=1; i<num; i++){
    if( maxnum <= ( array[i] - minnum ) ){
      maxnum = array[i] - minnum;
    }

    if( minnum >= array[i] ){
      minnum = array[i];
    }
  }

  printf("%d\n", maxnum);

  return 0;
}

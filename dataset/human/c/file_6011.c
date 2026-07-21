#include <stdio.h>
#include <stdlib.h>
#define N 200000
#define RT 1000000000

int main()
{
  int i,n,R[N],max=-RT,mi,d;
  scanf("%d",&n);
  if( n > N  || n < 2 )
    exit(1);
  for( i = 0; i <n ; i++ )
    {
      scanf("%d",&R[i]);
      if( R[i] > RT || R[i] < 1 )
	exit(1);
    }
  
  mi=R[0];
  for( i = 1; i < n; i++ )
    {
      d = R[i]-mi;
      if( d>max )
	max = d;
      if( R[i]<mi )
	mi = R[i];
    }
  printf("%d\n",max);
  return 0;
}

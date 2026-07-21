#include <stdio.h>

int main()
{
  int j, n, maxv, minv, R[200000];

  scanf("%d",&n);
  for( j=0 ; j<n ; j++ )
    scanf("%d",&R[j]);

  minv = R[0];
  maxv = R[1] - R[0];

  for( j=1 ; j<n ; j++ ){
    if(R[j]-minv>maxv) maxv = R[j]-minv;
    if(minv>R[j]) minv = R[j];
  }
  printf("%d\n",maxv);
  return 0;
}

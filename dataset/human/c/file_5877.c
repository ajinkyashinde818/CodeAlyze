#include <stdio.h>

#define MAX 200000

int main()
{
  int n;
  int i;
  int maxv,minv;
  int R[MAX];

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&R[i]);
    }
  maxv = -2000000000;
  minv = R[0];
  for(i = 1; i < n; i++)
    {
      maxv = (maxv <= R[i] - minv) ? R[i] - minv : maxv;
      minv = (minv >= R[i] ) ? R[i] : minv;
    }

  printf("%d\n",maxv);

  return 0;
}

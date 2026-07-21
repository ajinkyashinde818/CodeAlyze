#include<stdio.h>

#define N 200000

int main()
{
  int i,j,maxv,minv,n,a,R[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++)
  {
    scanf("%d",&a);
    R[i] = a;
  }

  minv = R[0];
  maxv = -2000000000;
  
  for(j = 1; j < n; j++)
  {
    if(maxv < R[j] - minv)maxv = R[j] - minv;
    if(minv > R[j])minv = R[j];
  }

  printf("%d\n",maxv);

  return 0;
}

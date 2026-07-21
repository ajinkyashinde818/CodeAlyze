#include<stdio.h>

int getBenefit(int*, int);

int main()
{
  int i,n,R[200000];
  
  scanf("%d", &n);
  for(i=0;i<n;i++)
    {
      scanf("%d", &R[i]);
    }

  printf("%d\n", getBenefit(R,n));
  return 0;
}

int getBenefit(int *R, int n)
{
  int j, maxv = R[1] - R[0], minv = R[0];
  for(j=1;j<=n-1;j++)
    {
      /*条件演算子*/
      maxv = maxv > R[j] - minv ? maxv : R[j] - minv;
      minv = minv < R[j] ? minv : R[j];
    }
  return maxv;
}

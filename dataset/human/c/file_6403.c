#include<stdio.h>
#include<math.h>

int main()
{
  int n,minv,maxv,i,j,a[200000];

  scanf("%d",&n);
  
  for(i = 0;i < n;i++)
    scanf("%d",&a[i]);

  minv = a[0];
  maxv = -1000000000;
  for(j = 1;j <= n - 1;j++)
    {
      if(maxv < a[j] - minv)
	maxv = a[j] - minv;

      if(minv > a[j] )
	minv = a[j];
    }
  printf("%d\n",maxv);

  return 0;
}

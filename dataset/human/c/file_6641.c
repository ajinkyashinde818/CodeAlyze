#include <stdio.h>
#define N 200000

int main()
{
  int n,min,max,i;
  int r[N];

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&r[i]);

  max = -999999999;
  min = r[0];
  
  for(i = 1;i < n;i++)
    {
      if(max < r[i] - min) max = r[i] - min;
      if(min > r[i]) min = r[i];
    }

  printf("%d\n",max);

  return 0;
}

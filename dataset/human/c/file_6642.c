#include<stdio.h>

int main()
{
  int max, min, n, i, j, a[200000];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }

  i = a[0];
  max = a[1]-i;
    
  for(j=1; j<n; j++)
    {
      min = i;
      if(a[j] <= min) i=a[j];
      
      if(a[j]-min >= max) max = a[j]-min;
    }

  printf("%d\n", max);
  
  return 0;
}

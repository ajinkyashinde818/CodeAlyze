#include<stdio.h>
int main()
{
  int n, rt[200000], i, j, ri = 0, sum = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &rt[i]);
    }
  ri = rt[0];
  sum = rt[1] - ri;
  for(i = 1; i < n; i++)
    {
      if(sum < rt[i] - ri) sum = rt[i] -ri;
      if(ri > rt[i]) ri = rt[i];
    }
  printf("%d\n", sum);
}

#include <stdio.h>

int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  int h[n];
  int counter;
  counter = 0;
  
  int i;
  i = 0;
  while (i < n)
  {
    scanf("%d", &h[i]);
    if (h[i] >= k)
      counter++;
    i++;
  }
  printf("%d",counter);
}

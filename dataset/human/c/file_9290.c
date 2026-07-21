#include <stdio.h>
int main(void)
{
  int i, n, k, h[100000], count=0;
  scanf("%d%d", &n, &k);
  for(i=0; i<n; i++)
    scanf("%d", &h[i]);
  for(i=0; i<n; i++){
    if(h[i] >= k)
      count++;
  }
  printf("%d", count);
  return 0;
}

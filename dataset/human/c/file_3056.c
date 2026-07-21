#include <stdio.h>

int main(void)
{
  int k, n, a[200000], max;

  scanf("%d%d", &k, &n);
  for(int i=0;i<n;i++)
    scanf("%d", &a[i]);
  max=k-a[n-1]+a[0];
  for(int i=0;i<n-1;i++){
    if(max<a[i+1]-a[i])
      max=a[i+1]-a[i];
  }
  printf("%d", k-max);

  return 0;
}

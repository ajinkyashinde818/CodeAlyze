#include <stdio.h>
int main(void)
{
  int k,n;
  scanf("%d",&k);
  scanf("%d",&n);
  int a[n],i,max;
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  max=a[0]+(k-a[n-1]);
  for(i=1;i<n;i++)
    if(a[i]-a[i-1]>max)
      max=a[i]-a[i-1];
  printf("%d",k-max);
  
  return 0;
}

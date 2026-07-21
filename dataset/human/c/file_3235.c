#include <stdio.h>

int main(void)
{
  int i,k,n,longest=0,emc=0;
  scanf("%d",&k);
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    if(i>=1&&a[i]-a[i-1]>longest)
      longest=a[i]-a[i-1];
  }
  if((a[0]+(k-a[n-1]))>longest)
     longest=a[0]+(k-a[n-1]);
  emc=k-longest;
  printf("%d",emc);
  
  return 0;
}

#include <stdio.h>
int main(void)
{
  int i,k,n;
  scanf("%d%d", &k, &n);
  int a[n];
  for(i=0;i<n;i++) {
  scanf("%d",&a[i]);
  }
  int l[n];
  for(i=0;i<n-1;i++){
  l[i]=a[i+1]-a[i];
  }
  l[n-1]=k+a[0]-a[n-1];
  int max=l[0];
  for(i=0;i<n;i++){
  if(l[i]>max)
    max=l[i];
  }
  int t=0;
  for(i=0;i<n;i++){
  t = t + l[i];
  }
  t = t - max;
  printf("%d",t);
  
  return 0;
}

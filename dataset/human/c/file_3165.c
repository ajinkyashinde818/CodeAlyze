#include <stdio.h>
 
int main(void)
{
    int i,k,n;
  k=0;
  n=0;
  scanf("%d",&k);
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {
  scanf("%d",&a[i]);
  }
  int kyori[n];
  
  for(i=0;i<n-1;i++)
  {
  kyori[i]=a[i+1]-a[i];
  }
  kyori[n-1]=k+a[0]-a[n-1];
  int max=kyori[0];
  for(i=0;i<n;i++)
  {
  if(kyori[i]>max)
    max=kyori[i];
  }
  int total=0;
  for(i=0;i<n;i++)
  {
  total=total+kyori[i];
  }
  total=total-max;
  printf("%d",total);
  
  return 0;
}

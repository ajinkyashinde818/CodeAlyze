#include <stdio.h>
int main(void)
{
  int n,k,i,f,h[100000];
  
  scanf("%d%d",&n,&k);
  
  for(i=0;i<n;i++)
    scanf("%d",&h[i]);
  
  f=0;
  for(i=0;i<n;i++)
    if(h[i]>=k) f++;
  printf("%d\n",f);
  return 0;
}

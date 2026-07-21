#include<stdio.h>

int main(void)
{
  int n,k;
  scanf("%d%d",&n,&k);
  int c=0,h[n],i;
  for(i=0;i<n;i++){
    scanf("%d",&h[i]);
    if(h[i]>=k)
      c++;
  }
  printf("%d\n",c);
  return 0;
}

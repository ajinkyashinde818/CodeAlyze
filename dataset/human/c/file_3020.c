#include<stdio.h>
int main(void)
{
  int k,n,af,i,a,aa,maxd=0;
  
  scanf("%d%d%d",&k,&n,&af);
  aa=af;
  for(i=1; i<n; i++) {
     scanf("%d",&a);
     if(maxd < a-aa) maxd=a-aa;
     aa=a;
  }
  if(maxd < k-a+af) maxd=k-a+af;
  
  printf("%d\n",k-maxd);
  
  return 0;
}

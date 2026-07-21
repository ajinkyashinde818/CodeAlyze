#include<stdio.h>
 
int main(void)
{
  int n,k,c=0;
  
  scanf("%d%d",&n,&k);
  int h[n];
  for(int i=0;i<n;i++){scanf("%d",&h[i]);}
  for(int i=0;i<n;i++){
      if(h[i]>=k){c++;}
  }
  printf("%d",c);
  return 0;
}

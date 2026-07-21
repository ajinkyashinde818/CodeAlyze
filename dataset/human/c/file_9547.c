#include <stdio.h>

int main(void)
{
  int n , d , x;
  scanf("%d %d %d",&n,&d,&x);
  
  int a[n];
  for(int i = 0; i < n;i ++){
  scanf("%d",&a[i]);
  }
  
  int niti , count = x;
  
  for(int i = 0;i < n;i ++){
    niti = 1;
    while(niti<=d){
      count ++;
      niti += a[i];
    }
  }
 printf("%d",count);
  
  return 0;
}

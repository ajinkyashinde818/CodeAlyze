#include<stdio.h>
#define min(a,b) (a)<(b)?(a):(b)
int main(void)
{
  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);
  for(int i=min(a,b);i<=a||i<=b;i--){
    if(a%i==0&&b%i==0){
      k--;
    }
    if(k==0){
      printf("%d",i);
      break;
    }
  }
  return 0;
}

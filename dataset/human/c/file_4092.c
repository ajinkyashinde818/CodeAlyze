#include <stdio.h>

int main(void)
{
  int A,B,K,i,a,b,x,y;

  scanf("%d%d%d",&A,&B,&K);

  a = 0;
  b = 0;
  if (A > B){
    a = B;
  }
  else {
    a = A;
  }
  for (i=a;b<K;i--){
    x = A % i;
    y = B % i;
    if (x==0 && y==0){
      b++;
    }
  }
  printf("%d\n",i+1);
  return 0;
}

#include<stdio.h>

int main(void)
{
  int a,b,k;
  scanf("%d%d%d",&a,&b,&k);

  int i,c[100],j=0;
  for(i=1;(i<=a)||(i<=b);i++)
    if((a%i==0)&&(b%i==0)){
      j++;
      c[j]=i;
    }

  printf("%d\n",c[j-k+1]);
  return 0;
}

#include<stdio.h>

int main(void)
{
  int a,b,c=0;
  int i,j,l;

  scanf("%d %d",&a,&b);

  for(i=0;i<=a;i++){
    for(j=0;j<=a;j++){
      l=b-i-j;
      if(l<=a &&l>=0)
        c++;
    }
  }

  printf("%d\n",c);

  return 0;
}

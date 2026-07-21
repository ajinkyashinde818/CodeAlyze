#include<stdio.h>

int yon(int a){

  while(a){
    if(a%10==9) return 1;
     a=a/10;
  }
  return 0;
}

int main(void)
{
  int n,a;

  scanf("%d",&n);

  if(a=yon(n))
    printf("Yes\n");
  else
    printf("No\n");

  return 0;
}

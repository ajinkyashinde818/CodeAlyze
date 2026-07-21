#include <stdio.h>
#include <stdlib.h>

void Constraints(int x,int i) //制約関数の宣言
{
  if(1<=x&&x<=10000&&i<=10000){}
  else
  {}
}

int main(void)
{
  int x=1;
  int i=0;
  while(x!=0){
    i++;
    scanf("%d",&x);
    Constraints(x,i);
    if(x!=0){
      printf("Case %d: %d\n",i,x);
    }
  }
	return 0;
}

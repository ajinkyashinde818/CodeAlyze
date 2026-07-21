#include<stdio.h>

int main()
{
  int A,B,C,D;
  int S1,S2;

  scanf("%d%d%d%d",&A,&B,&C,&D);

  S1=A*B;
  S2=C*D;

  if(S1>=S2){
    printf("%d\n",S1);
  }

  else{
    printf("%d\n",S2);
  }

  return 0;
}

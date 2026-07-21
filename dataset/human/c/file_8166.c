#include<stdio.h>
int main(void){
  int A,B,C,D;
  scanf("%d%d%d%d",&A,&B,&C,&D);
  int sq_1=A*B;
  int sq_2=C*D;
  if(sq_1>sq_2)
    printf("%d\n",sq_1);
  else
    printf("%d\n",sq_2);
  return 0;
}

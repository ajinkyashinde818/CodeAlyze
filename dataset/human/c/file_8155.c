#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
   int A,B,C,D;
   scanf("%d%d%d%d",&A,&B,&C,&D);

   printf("%d\n",max(A*B,C*D));

  return 0;
}

#include <stdio.h>
#include <string.h>

int main(void){
   
   int A,B,C;
   
   scanf("%d %d %d",&A,&B,&C);
   
   if(A + B >= C - 1){
      printf("%d\n",B + C);
   }
   else {
      printf("%d\n",2*B + A + 1);
   }
   
   return 0;
}

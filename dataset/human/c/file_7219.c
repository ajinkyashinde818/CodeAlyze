#include<stdio.h>

int main(void){
   int x,y,i,j;
   for(;;){
      scanf("%d %d",&y,&x);
      if(x+y==0) break;
      for(i=0;i<y;i++){
         for(j=0;j<x;j++)
            if((i+j)%2==0)
               printf("#");
            else
               printf(".");
         printf("\n");
      }
   printf("\n");
   }
   return 0;
}

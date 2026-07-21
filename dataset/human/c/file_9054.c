#include <stdio.h>
 
int main (void){
   int num1,num2,i;
   int count=0;
   scanf("%d %d",&num1,&num2);
   int high[num1];
   for(i=0;i<num1;i++){
       scanf("%d",&high[i]);
       if(high[i]>=num2){
           count++;
       }
   }
   printf("%d",count);
   return 0;
}

#include <stdio.h>
int main(void){
   int n,d,x;
   scanf("%d %d %d",&n,&d,&x);
   
   int choco[n];
   int i,j;
   int count=0;
   
   for(i=0;i<n;i++){
       scanf("%d",&choco[i]);
       for(j=0;j<d;j++){
           if(j*choco[i]<d){
               count++;
           }
       }   
       
   }
   
   printf("%d\n",count+x);
   
   return 0;
}

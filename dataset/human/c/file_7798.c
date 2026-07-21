#include <stdio.h>
int main(void){
   
   
   int n,k,p,i,stone;
   scanf("%d",&n);
   for(i=1;i<=n;i++){
       scanf("%d %d",&k,&p);
       stone=k%p;
       if(stone==0){
           stone=p;
       }
       
       
       printf("%d\n",stone);
       
       
   }
}

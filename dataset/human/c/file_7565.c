#include<stdio.h>
int main(void){
   int a[20000],i,k;

   for(i=1;i<=20000;i++){
      scanf("%d",&a[i]);
      if(a[i]==0){
         k=i;
         break;
      }
   }
   for(i=1;i<=k-1;i++){
      printf("Case %d: %d\n",i,a[i]);
   }

   return 0;
}

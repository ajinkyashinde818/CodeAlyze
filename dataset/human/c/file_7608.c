/*ITP1_3_B.c*/
#include<stdio.h>
int main(void){
   int a[10000],i,j;
   for(i=1;i>=1;i++){
      scanf("%d",&a[i]);
      if(a[i]==0){
         break;
      }
   }
   for(j=2;j<=i;j++){
      printf("Case %d: %d\n",j-1,a[j-1]);
   }
   return 0;
}

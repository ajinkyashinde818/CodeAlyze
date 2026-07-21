#include <stdio.h>

int main(void){
   int n,k,i,count=0;
   scanf("%d%d",&n,&k);

   int h[n];
   for(i=0;i<n;i++)
      scanf("%d",&h[i]);

   for(i=0;i<n;i++){
      if(h[i]>=k) count++;
   }

   printf("%d\n",count);

   return 0;
}

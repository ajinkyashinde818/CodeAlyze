#include<stdio.h>

int main(void)
{
   int n, k, h[100000], s=0, i;

   scanf("%d%d",&n,&k);
   for(i=0;i<n;i++){
      scanf("%d",&h[i]);
      if(h[i]>=k)
         s++;
   }
   printf("%d\n",s);
   return 0;
}

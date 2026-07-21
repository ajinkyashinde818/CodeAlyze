#include<stdio.h>

int main(void)
{
   int n, a[100000], i, x=0, z[100000]={0};

   scanf("%d",&n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   i=0;
   while(x!=1){
      x=a[x]-1;
      if(z[x]==1){
         printf("-1\n");
         return 0;
      }
      z[x]=1;
      i++;
   }

   printf("%d\n",i);
   return 0;
}

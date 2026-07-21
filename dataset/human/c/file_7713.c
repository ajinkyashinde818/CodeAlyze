#include<stdio.h>

int main(void)
{
   int i,x;
   int a[10000];

   for(i=0;;i++)
   {
      scanf("%d",&a[i]);
      if(a[i]==0)
      {
         break;
      }
   }

   x=i;
   i=0;

   while(i<x)
   {
      printf("Case %d: %d\n",i+1,a[i]);
      i++;
   }

   return 0;
}

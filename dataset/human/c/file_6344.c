#include<stdio.h>
int main()
{  int i,n,t,j,max,min,a[200000];
   scanf("%d",&n); 
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   max=-2000000000;
   min=a[0];
   for(i=1;i<n;i++)
   {  if(max>=a[i]-min) max=max; else max=a[i]-min;
      if(min<=a[i])  min=min; else min=a[i];
   }
   printf("%d\n",max);
   return 0;
}

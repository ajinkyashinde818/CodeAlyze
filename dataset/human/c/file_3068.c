#include<stdio.h>
int main()
{  int k,n,a[200000],i,l,lx;
   scanf("%d%d",&k,&n);
   for(i=0;i<n;i++)
   scanf("%d",&a[i]);
   lx=a[0]+k-a[n-1];
   for(i=1;i<n;i++)
   {  l=a[i]-a[i-1];
      if(l>lx) lx=l;
   }
   printf("%d",k-lx);
}

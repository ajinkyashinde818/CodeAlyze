#include<stdio.h>

int main(void)
{
   int n,d,x,a[101],i,j,s=0;

   scanf("%d%d%d",&n,&d,&x);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);

   for(i=0;i<n;i++){
      for(j=1;j<=d;j+=a[i])
         s++;
   }
   printf("%d\n",s+x);
   return 0;
}

#include <stdio.h>

int main(void)
{
   int n,d,x,a[100],i,j,count=0;

   scanf("%d",&n);
   scanf("%d%d",&d,&x);

   for(i=1;i<=n;i++)
      scanf("%d",&a[i]);

   for(i=1;i<=n;i++){
      for(j=1;j<=d;j=j+a[i]) count++;
   }
   printf("%d",count+x);

   return 0;
}

#include<stdio.h>

int main(void)
{
   int n,d,x,i,o,s,j,a[100];

   scanf("%d",&n);
   scanf("%d%d",&d,&x);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   s=0;
   for(i=0;i<n;i++){
     for(j=1;j<=d;j=j+a[i])
        s++;
   }

   printf("%d\n" ,s+x);
   return 0;
}

#include<stdio.h>

int main(void)
{
   int n, a[20], b[20], c[19], i, s=0;

   scanf("%d",&n);
   for(i=0;i<n;i++)
      scanf("%d",&a[i]);
   for(i=0;i<n;i++){
      scanf("%d",&b[i]);
      s+=b[i];
   }
   for(i=0;i<n-1;i++)
      scanf("%d",&c[i]);

   for(i=0;i<n-1;i++)
      if(a[i]==a[i+1]-1)
         s+=c[a[i]-1];

   printf("%d\n",s);
   return 0;
}

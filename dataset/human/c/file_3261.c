#include <stdio.h>

int main(){
   int k,n,i,m,a,b,f;

   scanf("%d %d",&k,&n);
   scanf("%d",&b);
   f=b;
   m=0;
   for (i=1;i<n;i++) {
      scanf("%d",&a);
      if (a-b>m) m=a-b;
      b=a;
   }
   a=k-b+f;
   if (a>m) m=a;
   printf("%d\n",k-m);
   return 0;
}

#include <stdio.h>

int main(void)
{

   int n,i,d,j,p,x,a[100],b[100],s;

   scanf("%d%d%d",&n,&d,&x);

   for(i=0;i<n;i++){
      scanf("%d",&a[i]);
      b[i]=0;
   }

   for(i=0;i<n;i++){
      p = 1;
      for(j=1;j<=d;j++){
         if(p==j){
            b[i]++;
            p+=a[i];
         }
      }
   }

   s=0;

   for(i=0;i<n;i++){
      s = s+b[i];
   }

   s+=x;

   printf("%d\n",s);

   return 0;

}

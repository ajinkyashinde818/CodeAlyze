#include <stdio.h>

int main(){
   long a,mi,s;
   int n,i,m;
    
   scanf("%d",&n);
   for (m=i=0;i<n;i++) {
      scanf("%ld",&a);
      if (i==0) 
         if (a>=0) mi=a;
         else      mi=-a;
      if (a>=0) {
         s+=a;
         if (a<mi) mi=a;
      } else {
         s-=a;
         m++;
         if (-a<mi) mi=-a;
      }
   }
   if (m%2==0) printf("%ld\n",s);
   else        printf("%ld\n",s-mi*2);
   return 0;
}

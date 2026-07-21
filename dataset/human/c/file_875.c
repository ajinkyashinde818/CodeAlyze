#include <stdio.h>

int main(){
   long n,i;
   int  j,k,a;

   scanf("%ld",&n);
   if (n%2==0) {
      n/=2;
      for (j=1;n%2==0;j++) n/=2;
      for (k=1;j>=k;k++) j-=k;
      a=k-1;
   } else
      a=0;
   for (i=3;i*i<=n;i+=2) 
      if (n%i==0) {
         n/=i;
         for (j=1;n%i==0;j++) n/=i;
         for (k=1;j>=k;k++) j-=k;
         a+=k-1;
      }
   if (n>1) a++;
   printf("%d\n",a);
   return 0;
}

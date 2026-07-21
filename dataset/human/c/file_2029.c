#include <stdio.h>
 
int main(){
   long a,b,c,n;
    
   scanf("%ld %ld %ld",&a,&b,&c);
   if (b<c) {
     n=2*b;
     c-=b;
   } else {
     n=b+c;
     c=0;
   }
   if (c>0 && c<=a) {
     n+=c;
     c=0;
   } else if (c>a) {
     n+=a;
     c-=a;
   }
   if (c>0) n++;
   printf("%d\n",n);
   return 0;
}

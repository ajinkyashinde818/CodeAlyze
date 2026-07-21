#include <stdio.h>
#include <math.h>
int main(){
   int a, b, c, d;
   long int s, t;
   scanf("%d%d%d%d", &a, &b, &c, &d);
   s = a*b;
   t = c*d;
   if(s >= t){
       printf("%ld\n", s);
   }
   else{
       printf("%ld\n", t);
   }
   return 0;
}

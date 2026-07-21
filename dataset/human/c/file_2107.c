#include <stdio.h>
     
    int main(){
       long n,i,j,d2,d5,d10;
     
       scanf("%ld",&n);
       if (n%2==0) {
          d5=0;
          for (i=10;i<=n;i*=5) d5+=n/i;
          printf("%ld\n",d5);
       } else {
          printf("%ld\n",0);
       }
       return 0;
    }

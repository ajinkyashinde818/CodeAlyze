#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
int main (void) {
long long int A,B;
scanf("%lld %lld",&A,&B);
long long int min =1;
long long int max1 = 0;
if (A>B)  {min=B;
            max1=A;}
else if (A<B) {min=A;max1=B;}

long long int max =1;

for (long long int i=1;i<=min;i++){
    if ((A%i==0) && (B%i==0)) {max=i;}
}
printf("%lld",max1*min/max);

return EXIT_SUCCESS;
}

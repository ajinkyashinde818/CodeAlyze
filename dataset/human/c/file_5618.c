#include <stdio.h>

int main()
{
 long x;
scanf("%ld",&x);
long as;
long a=0;
long k=x/11;
long r=x%11;
if(r==0) as=0;
 else if(r<=6)
as=1;
else as=2;
a=2*k+as;
printf("%ld",a);




return 0;}

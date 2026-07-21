#include<stdio.h>

int main()
{
 long long int A;
 long long int B;
 long long int C;
 long long int out;

 scanf("%lld %lld %lld",&A,&B,&C);
 if(C<=B-1) out = B+C;
 if((C>B-1)&&(C-B-1<=A)) out = B + C; 
 if((C>B-1)&&(C-B-1>A)) out = 2*B + 1+ A;

 printf("%lld\n",out);

 return 0;
}

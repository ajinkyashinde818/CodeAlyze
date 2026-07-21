#include<stdio.h>

int gcd(long int a, long int b)
{
    while (a%b!=0)
    {
        long int z;
        z = a;
        a = b;
        b = z % b;
    }
    return b;
}

int main()
{
   long int A, B, g;
   scanf("%ld %ld",&A,&B);
   g = gcd(A,B);
   printf("%ld\n",A*B/g);
   return 0;
}

#include<stdio.h>
long long sum;
void fa(long long n)
{
    if(n >= 5)
    {
        sum += n / 5;
        return fa(n/5);
    }
    else return;
}
int main()
{
    long long  n;
    scanf("%lld",&n);
    if(n % 2) printf("0\n");
    else
    {
        fa( n / 2);
        printf("%lld",sum);
    }
    return 0;
}

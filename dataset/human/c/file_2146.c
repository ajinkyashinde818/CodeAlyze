#include <stdio.h>

int main()
{
    long long n,ans = 0;
    scanf("%lld",&n);

    if(n < 2 || n % 2 == 1)
    {
        printf("0");
    }
    else
    {
        n /= 2;
        long long num = 5;
        while (num <= n)
        {
            ans += n / num;
            num *= 5;
        }
        printf("%lld",ans);
    }
}

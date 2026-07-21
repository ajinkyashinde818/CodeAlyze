#include <stdio.h>

#define INF 1e18

long long llabs(long long a)
{
    if(a < 0)return -a;
    else return a;
}

int main()
{
    long long n,a,sum[200001] = {0},i,min = INF;
    
    scanf("%lld",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld",&a);
        sum[i + 1] = sum[i] + a;
    }
    for (i = 1; i < n; i++)
    {
        if(llabs(sum[n] - sum[i] - sum[i]) < min)min = llabs(sum[n] - sum[i] - sum[i]);
    }
    printf("%lld",min);
}

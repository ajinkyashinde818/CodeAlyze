#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *prime(void)
{
    int c, cc, max = (int)10e+6;
    int *ans;
    ans = (int *)malloc(sizeof(int) * (max + 1));
    for (c = 0; c <= max; c += 2)
    {
        ans[c] = 0;
    }
    for (c = 3; c <= max; c += 2)
    {
        ans[c] = c;
    }
    ans[2] = 2;
    for (c = 3; c <= (int)10e+3; c += 2)
    {
        if (ans[c] == 0)
        {
            continue;
        }
        for (cc = 2; cc * c <= max; ++cc)
        {
            ans[c * cc] = 0;
        }
    }
    return ans;
}

long powllong(long long c, int power)
{
    int cc;
    long long c0 = c;
    for (cc = 0; cc < power - 1; ++cc)
    {
        c *= c0;
    }
    return c;
}

int main(void)
{
    int *key;
    int c, ans = 0, power;
    long long N, N0;
    scanf("%lld", &N);
    N0 = N;
    if (N == 1)
    {
        printf("0");
        return 0;
    }
    key = prime();
    for (c = 2; c <= (int)10e+6 + 2; ++c)
    {
        if (key[c] != 0)
        {
            power = 1;
            while (N % powllong((long long)c, power) == 0)
            {
                ++ans;
                N /= powllong((long long)c, power);
                ++power;
            }
        }
    }
    if (N == 1)
    {
        printf("%d", ans);
        return 0;
    }
    for (c = 2; c <= (int)10e+6 + 2; ++c)
    {
        if (key[c] != 0 && N % key[c] == 0)
        {
            printf("%d", ans);
            return 0;
        }
    }
    ++ans;
    printf("%d", ans);
    return 0;
}

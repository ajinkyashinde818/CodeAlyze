#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;

ll prime[100000] = {0}, cnt = 0;

ll prime_factorization(ll a)
{
    ll i, sq;

    if (a % 2 == 0)
    {
        prime[cnt++] = 2;
        return prime_factorization(a / 2);
    }

    sq = sqrt(a);
    for (i = 3; i <= sq; i += 2)
        if (a % i == 0)
        {
            prime[cnt++] = i;
            return prime_factorization(a / i);
        }

    if (a != 1)
        prime[cnt++] = a;
    return 0;
}

int main(void)
{
    ll n;
    int ans = 0;
    scanf("%lld", &n);
    prime_factorization(n);

    int num = -1, numCnt = 0, ansCnt = 0;
    rep(i, cnt)
    {
        if (num != prime[i])
        {
            ans++;
            ansCnt = 1;
            ;
            num = prime[i];
            numCnt = 0;
        }
        else
        {
            numCnt++;
            if (numCnt > ansCnt)
            {
                ans++;
                ansCnt++;
                numCnt = 0;
            }
        }
    }

    printf("%d", ans);
    return 0;
}

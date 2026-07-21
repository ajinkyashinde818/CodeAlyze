/* AtCoder Regular Contest 078. Problem , by Abreto<m@abreto.net>. */
#include <stdio.h>

#define MAXN    200001
typedef long long int ll;

ll llabs(ll x){return (x<0)?(-x):x;}

int N;
ll A[MAXN];
ll sum[MAXN];
ll tot;
ll mind;

int main(void)
{
    int i = 0;
    ll t = 0;

    scanf("%d", &N);
    for(i = 1;i <= N;++i)
    {
        scanf("%lld", A+i);
        sum[i] = A[i] + sum[i-1];
        tot += A[i];
    }
    mind = llabs(sum[1]*2-tot);
    for(i = 1;i < N;++i)
    {
        if( (t=llabs(sum[i]*2-tot)) < mind )
            mind = t;
    }

    printf("%lld\n", mind);
    return 0;
}

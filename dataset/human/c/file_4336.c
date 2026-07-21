#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#define ll long long int




int main()
{

    ll N, M ;
    scanf("%lld %lld",&N,&M);
    ll d = N+1;
    ll array[d];
    memset(array,0,sizeof(array[0])*d);
    array[0]=1;
    array[1]=1;
    ll idx=0;
    ll a[M];
    for (ll i = 0; i<M; i++)
    {
        scanf("%lld",&a[i]);
        if (a[i]==1)
        {
            array[1]=0;
            idx++;
        }
    }


    for (ll i = 2; i<=N; i++)
    {
        if (i==a[idx] && idx<M)
        {
            idx++;
            continue;

        }
        array[i]=array[i-1]+array[i-2];
        array[i]=array[i]%1000000007;
    }


    printf("%lld",array[N]% 1000000007);



    return 0;
}

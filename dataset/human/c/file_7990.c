#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <assert.h>
typedef int64_t ll;
typedef uint64_t ull;
int acs(const void *a, const void *b){return *(int*)a - *(int*)b;} /* 1,2,3,4.. */
int des(const void *a, const void *b){return *(int*)b - *(int*)a;} /* 8,7,6,5.. */
#define min(a,b) (a < b ? a: b)
#define max(a,b) (a > b ? a: b)

#define MAXN (1000006)
#define MOD (1000000007)


// べき乗余
int64_t modpow(int64_t b, int64_t e)
{
    int64_t result = 1;
    while(e>0)
    {
        if(e&1) result = (result * b) % MOD;
        e >>= 1;
        b = (b * b) % MOD;
    }
    return result;
}

// 組み合わせ数
// nCk % MOD
ll cf[MAXN+1]; // 1*2*3*...*i
ll ci[MAXN+1]; // 1/ 1*2*3*...*i
void CombInit(ll n)
{
    cf[0] = 1;
    for(int i=1;i<=n;i++) cf[i] = cf[i-1] * i %MOD;
    ci[n] = modpow(cf[n],MOD-2);
    for(int i=n-1;i>=0;i--) ci[i] = ci[i+1] * (i+1) %MOD;
}
ll Comb(ll a,ll b)
{
    return cf[a]*ci[b]%MOD*ci[a-b]%MOD;
}
// カタラン数 2nまで参照することに注意
ll Catalan(ll n)
{
    return cf[2*n]*ci[n+1]%MOD*ci[n]%MOD;
}



int main(void)
{
    ll x,y;
    scanf("%ld %ld",&x,&y);
    CombInit(MAXN);

    if((x+y)%3!=0)
    {
        printf("0\n");
        return 0;
    }
    ll c2 = x - ((x+y)/3);
    ll c1 = ((x+y)/3) - c2;
    if(c2<0||c1<0)
    {
        printf("0\n");
        return 0;
    }
    printf("%ld\n",cf[c1+c2]*ci[c1]%MOD*ci[c2]%MOD);
    return 0;
}

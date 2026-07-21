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

#define MAXN (100001)
#define MOD (1000000007)

bool s[MAXN];
ll ans[MAXN+1];

int main(void)
{
    ll n,m;
    scanf("%ld %ld",&n,&m);
    for(int i=0;i<m;i++)
    {
        ll a;
        scanf("%ld",&a);
        s[a] = true;
    }

    ans[0] = 1;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]==false)
        {
            ans[i] += ans[i-1];
            ans[i] %= MOD;
        }

        if(i>=2&&s[i-2]==false)
        {
            ans[i] += ans[i-2];
            ans[i] %= MOD;
        }
    }

    printf("%ld\n", ans[n]);
    return 0;
}

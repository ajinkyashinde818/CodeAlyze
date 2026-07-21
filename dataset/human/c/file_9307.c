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

#define MAXN (200001)
#define MOD (1000000007)

int main(void)
{
    int n,k;
    scanf("%d %d",&n,&k);

    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        int h;
        scanf("%d",&h);
        if(h>=k) ans++;
    }
    
    printf("%ld\n", ans);
    return 0;
}

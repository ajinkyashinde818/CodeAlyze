#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#define MOD 1000000007
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a, MIN(b,c))
typedef long long lli;

int main()
{
    int n, m, i, a[100010], idx=0;
    lli dp[100010];
    scanf("%d%d",&n,&m);
    for(i=0; i<m; i++) {
        scanf("%d",a+i);
    }
    dp[0]=1;
    if(a[idx] == 1) {
        dp[1] = 0;
        idx++;
    } else {
        dp[1] = 1;
    }
    for(i=2; i<=n; i++) {
        if(i == a[idx]) {
            dp[i]=0;
            idx++;
        } else {
            dp[i] = (lli)(dp[i-1] + dp[i-2]);
            dp[i] %= MOD;
        }
        //printf("%d: %d\n",i,dp[i]);
    }
    printf("%lld",dp[n]);
    return 0;
}

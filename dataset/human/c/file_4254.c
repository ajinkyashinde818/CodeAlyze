#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 0x7f
#define MOD 1000000007

int max(int a,int b)
{
    if(a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    int n,m,a[100000],mcount = 0;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&a[i]);
    }
    
    int dp[100010];
    memset(dp,0,sizeof(dp));

    dp[0] = 1;

    for (int i = 1; i <= n ; i++)
    {
        if(i == a[mcount]){
            mcount++;
            dp[i] = 0;
        }
        else
        {
            if(i >= 2)dp[i] = dp[i - 2];
            dp[i] += dp[i - 1];
            dp[i] = dp[i] % MOD;
        }
        //for (int j = 0; j <= i; j++){printf("%d ",dp[j]);}printf("\n");
        
    }
    printf("%d",dp[n]);
}

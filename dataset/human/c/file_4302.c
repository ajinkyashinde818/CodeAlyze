#include<stdio.h>

const int MOD = 1e9+7;

int main(void){
        int n, m;
        scanf("%d %d", &n, &m);
        int a[n+1];
        for(int i=0; i<=n; i++) a[i]=1;
        for(int i=0; i<m; i++){
                int tmp;
                scanf("%d", &tmp);
                a[tmp] = 0;
        }

        long dp[n+1];
        for(int i=0; i<=n; i++) dp[i] = (i==0);
        for(int i=0; i<=n; i++){
                if(i>0) dp[i] = (dp[i] + dp[i-1]) * a[i] % MOD;
                if(i>1) dp[i] = (dp[i] + dp[i-2]) * a[i] % MOD;
        }

        printf("%ld ", dp[n]);
        return 0;
}

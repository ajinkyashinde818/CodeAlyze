#include <stdlib.h>
#include <stdio.h>
#define mod 1000000007

int main()
{   int n,m;
    scanf("%d%d",&n,&m);
    int a[m+1];
    a[m]=114514;
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }int k=0;
    int dp[n+1];
    dp[0]=1;
    if(a[0]==1){
        dp[1]=0;
        k++;
    }else{
        dp[1]=1;
    }
    for(int i=2;i<=n;i++){
        if(i==a[k]){
            dp[i]=0;
            k++;
        }else{
            dp[i]=dp[i-1]+dp[i-2];
            dp[i]%=mod;
        }
    }
    printf("%lld",dp[n]);

    return 0;
}

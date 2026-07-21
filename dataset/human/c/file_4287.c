#include <stdio.h>
int main(void){
    int dp[1000000] = {};
    int n,m;scanf("%d%d",&n,&m);
    int a[m];for(int i=0;i<m;i++)scanf("%d",&a[i]);
    int c=m-1;
    dp[n]=1;
    if(a[c]==n-1)c--;else dp[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(c>=0&&a[c]==i) c--;
        else dp[i]=(dp[i+1]+dp[i+2])%1000000007;
    }
    printf("%d",n==1?1:dp[0]);
}

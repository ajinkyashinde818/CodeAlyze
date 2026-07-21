#include <stdio.h>
const int N=1e3+10;
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
int main(){
    int n=1,dp[N][N],big;
    char c[N];
    while(n!=0){
        scanf("%d",&n);
        if(n==0)continue;
        big=0;
        for(int i=0;i<n;i++){
            scanf("%s",c);
            for(int j=0;j<n;j++)dp[i][j]=c[j]=='*'?0:1;
        }
        for(int i=0;i<n;i++)big=max(big,max(dp[i][0],dp[0][i]));
        for(int i=1;i<n;i++)for(int j=1;j<n;j++)if(dp[i][j]==1)big=max(big,dp[i][j]+=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]));
        printf("%d\n",big);
    }
    return 0;
}

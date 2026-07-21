#include <stdio.h>
const int N=1e3+10;
int max(int a,int b){return a>b?a:b;}
int main(){
    int d,g,p[N],c[N],dp[N][2],tot=0;
    bool f=false;
    scanf("%d%d",&d,&g);
    g/=100;
    for(int i=1;i<=d;i++){
        scanf("%d%d",&p[i],&c[i]);
        c[i]/=100;
        tot+=p[i];
    }
    for(int i=0;i<=tot;i++)dp[i][true]=dp[i][false]=0;
    for(int i=1;i<=d;i++){
        for(int j=0;j<p[i];j++)for(int k=j;k<=tot;k++)dp[k][f]=max(dp[k][f],dp[k-j][!f]+i*j);
        for(int j=p[i];j<=tot;j++)dp[j][f]=max(dp[j][f],dp[j-p[i]][!f]+i*p[i]+c[i]);
        f=!f;
    }
    for(int i=0;i<=tot;i++){
        if(dp[i][!f]>=g){
            printf("%d\n",i);
            return 0;
        }
    }
}

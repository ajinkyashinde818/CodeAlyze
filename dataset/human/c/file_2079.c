#include <stdio.h>
typedef long long int ll;
const int MOD=1e9+7;
const int N=2e3+10;
ll fac[N],ans[N][N];
ll pow(ll a,ll t){
    if(t==0)return 1;
    ll temp=pow(a,t/2);
    temp*=temp;
    temp%=MOD;
    if(t&1){
        temp*=a;
        temp%=MOD;
    }
    return temp;
}
ll rev(ll n){return pow(n,MOD-2);}
ll C(int n,int k){return (fac[n]*((rev(fac[k])*rev(fac[n-k]))%MOD))%MOD;}
ll H(int n,int k){return C(n+k-1,k);}
void init(){
    fac[0]=fac[1]=1;
    for(int i=2;i<N;i++)fac[i]=(fac[i-1]*i)%MOD;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)ans[i][j]=-1;
    ans[0][0]=1;
    return ;
}
ll dp(int n,int k){
    if(n<0||k<0)return 0;
    if(ans[n][k]>=0)return ans[n][k];
    if(n==k)return ans[n][k]=dp(n-1,k-1);
    return ans[n][k]=(dp(n-1,k-1))%MOD;
}
int main(){
    int n,k,now=1;
    ll ans=0;
    scanf("%d%d",&n,&k);
    if(n<=k)printf("1\n");
    else printf("0\n");
    //    init();
    
}

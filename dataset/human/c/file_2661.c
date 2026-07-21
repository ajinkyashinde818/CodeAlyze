#include <stdio.h>
typedef long long int ll;
const int N=4e3+10;
const int MOD=998244353;
ll f[N];
ll mul(ll a,ll b){return (a*b)%MOD;}
ll add(ll a,ll b){return (a+b)%MOD;}
ll pow(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1)ans=mul(ans,a);
        b>>=1;
        a=mul(a,a);
    }
    return ans;
}
ll rev(ll n){return pow(n,MOD-2);}
ll C(ll a,ll b){return a>=b&&b>=0?mul(f[a],mul(rev(f[b]),rev(f[a-b]))):0;}
int main(){
    f[0]=f[1]=1;
    for(int i=2;i<N;i++)f[i]=mul(f[i-1],i);
    int n,k,a;
    ll ans;
    scanf("%d%d",&k,&n);
    for(int i=2;i<=(k<<1);i++){
        ans=0;
        if(i&1){
            if(i>k)a=((k<<1)+1-i)>>1;
            else a=i>>1;
            for(int j=0;j<=a;j++)ans=add(ans,mul(C(a,j),mul(C(n+k-(a<<1)-1,n-j),pow(2,j))));
            printf("%lld\n",ans);
        }
        else{
            if(i>k)a=((k<<1)-i+2)>>1;
            else a=(i+1)>>1;
            for(int j=0;j<=a;j++)ans=add(ans,mul(C(a,j),mul(C(n+k-(a<<1)-1,n-j),pow(2,j))));
            //for(int j=0;j<=a;j++)ans=add(ans,mul(C(a,j),mul(C(n+k-(a<<1)-2,n-j-1),pow(2,j))));
            printf("%lld\n",ans);
        }
    }
}

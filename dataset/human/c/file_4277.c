#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define max(p,q) ((p)>(q)?(p):(q))
#define min(p,q) ((p)<(q)?(p):(q))
#define chmax(a,b) ((a)=(a)>(b)?(a):(b))
#define chmin(a,b) ((a)=(a)<(b)?(a):(b))
#define abs(p) ((p)>=(0)?(p):(-(p)))
#define MOD 1000000007
ll powll(ll a,ll b){ll r=1;rep(i,b){r*=a;}return r;}
#define swap(a,b) do{ll w=(a);(a)=(b);(b)=w;}while(0)
#define swapd(a,b) do{double w=(a);(a)=(b);(b)=w}while(0)

//your code here!
ll fib(ll steps){
    if(steps<0) return 0;
    ll x0=0, x1=1, ret=1;
    rep(_, steps){
        ret = (x0+x1)%MOD;
        x0 = x1;
        x1 = ret;
    }
    return ret;
}
int main(void){
    ll N, M, a[100100], ans=1;
    scanf("%lld %lld", &N, &M);
    if(M==0){
        printf("%lld\n", fib(N));
        return 0;
    }
    rep(i, M) scanf("%lld", a+i);
    rep(i, M+1){
        if(i==0)      ans *= fib(a[0]-1);
        else if(i==M) ans *= fib(N-1-a[M-1]);
        else          ans *= fib(a[i]-a[i-1]-2);
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}

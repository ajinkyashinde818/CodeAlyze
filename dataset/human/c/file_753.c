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
int main(void){
    ll N, ans=1, alph[30]={0}, i=0;
    char S[100100];
    scanf("%lld %s", &N, S);
    while(S[i]!='\0') alph[S[i++]-'a']++;
    rep(i, 30) if(alph[i]>0) ans = (ans*(alph[i]+1)) % MOD;
    printf("%lld\n", --ans);
    return 0;
}

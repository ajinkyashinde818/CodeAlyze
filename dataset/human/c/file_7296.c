#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll h,w,k;
char s[310][310];
int a[310][310];
int main(){
	scanf("%lld%lld%lld",&h,&w,&k);
	rep(i,0,h)scanf(" %s",s[i]);
	
	ll l=0,cnt=0;
	rep(i,0,h){
		int flag=-1;
		rep(j,0,w)if(s[i][j]=='#')flag=j;
		if(flag==-1)continue;
		rep(j,0,w){
			rep(k,l,i+1)a[k][j]=cnt;
			if(s[i][j]=='#')cnt++;
		}
		rep(j,flag+1,w)rep(k,l,i+1)a[k][j]=cnt-1;
		l=i+1;
	}
	rep(i,l,h)rep(j,0,w)a[i][j]=a[l-1][j];
	
	rep(i,0,h){
		rep(j,0,w)printf("%d ",a[i][j]+1);
		puts("");
	}
}

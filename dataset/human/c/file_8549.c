#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

ll a[100010];
int main(){
	ll n;
	
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	sortup(a,n);
	//+側と-側に分ける。どっちも空はダメ
	
	ll s=a[n-1]-a[0];
	rep(i,1,n-1)s+=llabs(a[i]);
	printf("%lld\n",s);

	if(a[n-2]<0){
		//+側が1つのとき
		ll temp=a[n-1];
		rep(i,0,n-1){
			printf("%lld %lld\n",temp,a[i]);
			temp-=a[i];
		}
	}else{
		//+側が2つ以上のとき
		printf("%lld %lld\n",a[0],a[n-1]);
		if(n>2){
			ll temp=a[0]-a[n-1];
			int i=n-2;
			while(i>=2&&a[i-1]>0){
				printf("%lld %lld\n",temp,a[i]);
				temp-=a[i];
				i--;
			}
			printf("%lld %lld\n",a[i],temp);
			temp=a[i]-temp;
			i--;
			while(i>=1){
				printf("%lld %lld\n",temp,a[i]);
				temp-=a[i];
				i--;
			}
		}
	}
}

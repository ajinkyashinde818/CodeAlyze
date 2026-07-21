#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define INF ((1LL<<62)-(1LL<<31))
#define min(p,q)((p)<(q)?(p):(q))

ll a[100010];
ll n,cnt,ans;
int main(){
	scanf("%lld",&n);
	ll m=INF;
	rep(i,0,n){
		scanf("%lld",a+i);
		m=min(m,llabs(a[i]));
		ans+=llabs(a[i]);
		if(a[i]<0)cnt^=1;
	}
	if(cnt)ans-=2*m;	
	printf("%lld",ans);
}

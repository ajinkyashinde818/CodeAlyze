#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll k,s;
	scanf("%lld%lld",&k,&s);
	ll ans=0;
	rep(x,0,k+1)rep(y,0,k+1){
		ll z=s-x-y;
		if(0<=z&&z<=k)ans++;
	}
	printf("%lld",ans);
}

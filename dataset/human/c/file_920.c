#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

ll a[100010];
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n){
		ll l,r;
		scanf("%lld%lld",&l,&r);
		a[l]++;
		a[r+1]--;
	}
	ll ans=0;
	rep(i,1,100005){
		a[i]+=a[i-1];
		if(a[i]>=i-1)ans=i-1;
	}
	printf("%lld\n",ans);
}

#include <stdio.h>

typedef long long ll;

int main(){

	ll x;

	scanf("%lld",&x);

	ll ans;

	if(x%11ll==0ll){
		ans=x/11ll;
		ans*=2ll;
	}
	else{
		ans=x/11ll;
		ans*=2ll;
		x%=11ll;
		if(x<=6ll){
			ans+=1ll;
		}
		else{
			ans+=2ll;
		}
	}
	printf("%lld\n",ans);

	return 0;
}

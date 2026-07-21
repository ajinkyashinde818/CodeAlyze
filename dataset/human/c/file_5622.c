#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int main(void){
	ll x,ans=0,y;
	scanf("%lld",&x);
	y=x/11;
	ans=y*2;
	x%=11;
	if(x!=0){
		if(x<7)ans++;
		else ans+=2;
	}
	
	printf("%lld",ans);
	return 0;
}

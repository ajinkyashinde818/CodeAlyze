#include<stdio.h>
#include<string.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long

int main(){
	ll x,ans = 0;
	scanf("%lld",&x);
	ans = x / 11;
	ans *= 2;
	if(x%11 == 0){}
	else if(x%11 <= 6) ans += 1;
	else ans += 2;

	printf("%lld\n",ans);

}

#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

char s[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
ll a[110];
int main(){
	ll n;
	while(scanf("%lld",&n),n){
		rep(i,0,n)scanf("%lld",a+i);
		char t[110];
		scanf(" %s",t);
		ll len=strlen(t);
		rep(i,0,len)putchar(s[(strchr(s,t[i])-s-a[i%n]+52)%52]);
		puts("");
	}
}

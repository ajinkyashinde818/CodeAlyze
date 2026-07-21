#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=l;i<r;i++)

int g(char*s){
	ll ans=0;
	ll n=strlen(s);
	ll num=1;
	rep(i,0,n){
		if(s[i]<=57)num=s[i]-48;
		else{
			ll base;
			if(s[i]=='m')base=1000;
			if(s[i]=='c')base=100;
			if(s[i]=='x')base=10;
			if(s[i]=='i')base=1;
			ans+=num*base;
			num=1;
		}
	}
	return ans;
}

void f(int x){
	if(x>=1000){
		if(x/1000>1)printf("%d",x/1000);
		printf("m");
		x%=1000;
	}
	if(x>=100){
		if(x/100>1)printf("%d",x/100);
		printf("c");
		x%=100;
	}
	if(x>=10){
		if(x/10>1)printf("%d",x/10);
		printf("x");
		x%=10;
	}
	if(x>=1){
		if(x>1)printf("%d",x);
		printf("i");
	}
	puts("");
}

int main(){
	ll cnt;
	scanf("%lld",&cnt);
	while(cnt--){
		char s[10];
		char t[10];
		scanf(" %s %s",s,t);
		f(g(s)+g(t));
	}
}

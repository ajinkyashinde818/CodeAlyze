#include<stdio.h>

#define r0(a,b) ((0)>(a-b)?0:(a-b));

int main(){
	long long a,b,c,ans=0;
	scanf("%lld%lld%lld",&a,&b,&c);
	ans+=b;
	if(c-1<=a+b)ans+=c;
	else ans+=a+b+1;
	printf("%lld\n",ans);
	return 0;
}

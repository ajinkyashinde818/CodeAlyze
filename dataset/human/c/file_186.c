#include<stdio.h>

int _abs(int x){return x<0?-x:x;}

int main(){
	
	int n,i,x,k=0x3f3f3f3f,cnt=0;
	long long ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		if(x<0)cnt++,ans-=x;
		else ans+=x;
		if(_abs(x)<k)k=_abs(x);
	}
	if(cnt&1)printf("%lld",ans-2*k);
	else printf("%lld",ans);
	return 0;
}

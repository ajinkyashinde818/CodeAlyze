#include<stdio.h>

int main(void)
{
	int i,n,d,x,a,ans;
	scanf("%d%d%d",&n,&d,&x);
	ans=n+x;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		ans+=(d-1)/a;
	}
	printf("%d",ans);
	return 0;
}

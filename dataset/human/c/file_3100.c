#include <stdio.h>
#define max(p,q)((p)>(q)?(p):(q))

int a[200010];
int main(){
	int k,n;
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int ans=a[0]+k-a[n-1];
	for(int i=0;i<n-1;i++)ans=max(ans,a[i+1]-a[i]);
	printf("%d",k-ans);
}

#include <stdio.h>
int main(void){
	int i,n,k,ans=0;
	scanf("%d%d",&n,&k);
	int h[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
		if(h[i]>=k) ans++;
	}
	printf("%d",ans);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	int n,i,now=1,ans=0;;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	i=0;
	while(now!=2){
		now = a[now-1];
		ans++;
		if(ans==n+1){ans=-1;break;}
	}
	
	
	printf("%d",ans);
	return 0;
}

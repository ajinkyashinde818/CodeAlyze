#include <stdio.h>
int main(void){
	int n,d,x;
	scanf("%d",&n);
	scanf("%d %d",&d,&x);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int ans=0;
	for(i=0;i<n;i++){
		ans += 1 + (d-1)/a[i];
	}
	ans += x;
	printf("%d",ans);
	
	return 0;
}

#include <stdio.h>
int main(void){
	int n,i,sum=0;
	scanf("%d",&n);
	int a[n+1],b[n+1],c[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++) scanf("%d",&b[i]);
	for(i=0;i<n-1;i++) scanf("%d",&c[i]);
	for(i=0;i<n;i++){
		sum+=b[a[i]-1];
		if(i>0) if(a[i]-a[i-1]==1) sum+=c[a[i]-2];
	}
	printf("%d",sum);
	return 0;
}

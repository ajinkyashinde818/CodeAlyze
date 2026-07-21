#include<stdio.h>
int main(){
	int n,sum=0,i;
	int a[50],b[50],c[50];
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=n-1;i++) scanf("%d",&c[i]);
	c[i]=0;
	sum=b[a[1]];
	for(i=2;i<=n;i++){
		sum+=b[a[i]];
		if(a[i]==a[i-1]+1)
		    sum+=c[a[i-1]];
	}
	printf("%d",sum);
	return 0;
}

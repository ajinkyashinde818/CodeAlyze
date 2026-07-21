#include<stdio.h>
int main(void){
	int n,i,sum=0,r;
	int a[21],b[21],c[21];
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<=n-1;i++){
		scanf("%d",&c[i]);
	}
	for(i=1,r=a[1];i<=n;i++){
		sum+=b[a[i]];
		if(a[i]==r+1){
			sum+=c[a[i-1]];
		}
		r=a[i];
	}
	printf("%d",sum);
	return 0;
}

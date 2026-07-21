#include<stdio.h>
int main(void)
{
	int n,a[21],b[21],c[20],sum,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(i=1;i<n;i++){
		scanf("%d",&c[i]);
	}
	sum=0;
	for(i=1;i<=n;i++){
		sum+=b[a[i]];
		if(i!=1&&a[i]-a[i-1]==1){
			sum+=c[a[i-1]];
		}
	}
	printf("%d\n",sum);
	return 0;
}

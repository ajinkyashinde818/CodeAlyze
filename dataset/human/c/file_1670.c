#include<stdio.h>
int main(void)
{
	int n;
	int a[21],b[21],c[19];
	int i,j,k,sum;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(j=1;j<=n;j++){
		scanf("%d",&b[j]);
	}
	for(k=1;k<=n-1;k++){
		scanf("%d",&c[k]);
	}
	sum=0;
	for(i=1;i<=n;i++){
		sum+=b[a[i]];
	}
	for(i=1;i<=n-1;i++){
		if(a[i]+1==a[i+1]){
			sum+=c[a[i]];
		}
	}
	printf("%d\n",sum);
	return 0;
}

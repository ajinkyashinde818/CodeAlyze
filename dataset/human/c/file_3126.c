#include<stdio.h>
#include<stdlib.h>
int main(){
	long long sum=0;
	int k,n,max=0;
	int a[200000]={0};
	scanf("%d%d",&k,&n);
	for(int i=0;i<n;i++) {
		scanf("%d",&a[i]);	
		if(i>=1){
			sum+=a[i]-a[i-1];
			if(a[i]-a[i-1]>max) {
				max=a[i]-a[i-1];
			}
		}
	}	
	sum+=(k-a[n-1])+a[0];
	if((k-a[n-1])+a[0]>max) {
		max=(k-a[n-1])+a[0];
	}
	printf("%lld",sum-max);
	return 0;
}

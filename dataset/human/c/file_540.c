#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main(void){
	int n,i;
	long long int a,ans,sum,ans1;
	scanf("%d",&n);
	long long int SUNUsum[n];
	scanf("%lld",&a);
	SUNUsum[0]=a;
	for(i=1;i<n;i++){
		scanf("%lld",&a);
		SUNUsum[i] = SUNUsum[i-1]+a;
	}
	sum = SUNUsum[n-1];
	ans=abs(sum-2*SUNUsum[0]);
	for(i=0;i<n-1;i++){
		ans1 = labs(sum-2*SUNUsum[i]);
		if(ans1<ans) ans=ans1;
	}
	printf("%lld",ans);
	return 0;
}

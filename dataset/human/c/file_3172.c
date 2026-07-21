#include<stdio.h>

int main(void){
	long long int k,n,sum=0,now,temp,a1,max=0;
	scanf("%lld %lld",&k,&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&now);
		if(i==0){
			a1=now;
			temp=now;
		}
		sum+=now-temp;
		max=max>(now-temp)?max:(now-temp);
		temp=now;
	}
	sum+=a1+k-now;
	max=max>(a1+k-now)?max:(a1+k-now);
	printf("%lld",sum-max);
}

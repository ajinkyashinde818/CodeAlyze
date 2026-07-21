#include<stdio.h>

#define INF 2000000000000000000000000000

int main(){
		int n,i;
		long a[200000];
		long long sum=0,subsum[200001],min=INF;
		scanf("%d",&n);
		subsum[0]=0;
		for(i=0;i<n;i++){
				scanf("%ld",&a[i]);
				subsum[i+1]=subsum[i]+a[i];
				sum+=a[i];
		}
		for(i=1;i<n;i++){
				long long tmp=sum-subsum[i]*2;
				if(tmp<0)tmp=(-1)*tmp;
				if(tmp<min){
						min=tmp;
				}
		}
		printf("%lld\n",min);
		return 0;
}

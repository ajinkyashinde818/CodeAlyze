#include<stdio.h>

int main(void)
{
	long k,n;
	int i;

	for(i=0;i<2;i++){
		if(i==0){
			scanf("%ld",&k);
		}
		if(i==1){
			scanf("%ld",&n);
		}
	}

	long a[n];
	long max=0,start,m;

	for(i=0;i<n;i++){
		scanf("%ld",&a[i]);
	}

	for(i=1;i<n;i++){
		m=a[i]-a[i-1];
		if(max<m){
			max=m; start=i;
		}
	}
	if((k-a[n-1])+a[0]>max){
		max=(k-a[n-1])+a[0]; start=0;
	}

	long sum=0;

	for(i=start;i<n-1;i++){
		sum+=a[i+1]-a[i];
	}
	for(i=0;i<start-1;i++){
		sum+=a[i+1]-a[i];
	}
	if(start!=0){
		sum+=(k-a[n-1])+a[0];
	}

	printf("%ld\n",sum);
	
	return 0;
}

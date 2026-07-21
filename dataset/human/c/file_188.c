#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
//	printf("123");
	long long  a[100005],n,sum=0,min;
	int count=0;
	scanf("%lld",&n);
	//printf("%lld",n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]<0) count++;
	}
	for(int i=0;i<n;i++)
		{
			sum+=abs(a[i]);
		}
	if(count%2==0)
	{
		printf("%lld",sum);
	}else{
		min=abs(a[0]);
		for(int i=1;i<n;i++)
		{
			if(abs(a[i])<min) min=abs(a[i]);
		}
		sum=sum-2*min;
		printf("%lld",sum);
	}
}

#include<stdio.h>
#include<math.h>
long long int a[200000+50];
int main()
{
	long long int n;
	while(~scanf("%lld",&n))
	{
		long long int i,sum=0,k;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		k=fabs(sum-2*a[0]);
		for(i=0;i<n-1;i++)
		{
			sum-=2*a[i];
			if(k>fabs(sum))
				k=fabs(sum);
		}
		if(k<0)
				k*=-1;
		printf("%lld\n",k);
		
	}
}

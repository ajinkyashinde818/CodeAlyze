#include<stdio.h>
#include<math.h>
long long num[200000+50];
int main ()
{
	long long n;
	while(scanf("%lld",&n)!=EOF)
	{
		long long i,sn=0,k;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
			sn+=num[i];			
		}
		k=fabs(sn-2*num[0]);
		for(i=0;i<n-1;i++)
		{
			sn-=2*num[i];
			//printf("sn=%lld\n",sn);
			if(k>fabs(sn))
				k=fabs(sn);
			//printf("k=%lld\n",k);

		}	
		if(k<0)
			k*=-1;
		printf("%lld\n",k);
	} 
}

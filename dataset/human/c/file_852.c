#include<stdio.h>
#include<math.h>
int a[1000006];
int p[1000006],pt=0;
int main()
{
	long long n;
	scanf("%lld",&n);
	int ans=0;
	for(int i=2;i<=1000001;i++)
	{
		if(a[i]==0)
		{
			p[pt++]=i;
			for(int j=2;j*i<1000001;j++)
			{
				a[i*j]=1;
			}
		}
	}
	for(int i=0;i<pt;i++)
	{
		int f=0;
		while(n%p[i]==0)
		{
			f++;
			n/=p[i];
		}
		for(int j=1;j<=f;j++)
		{
			f-=j;
			ans++;
		}
	}
	if(n>1000000)
	ans++;
	printf("%d",ans);
}

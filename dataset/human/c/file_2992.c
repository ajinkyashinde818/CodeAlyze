#include<stdio.h>
int main()
{
	long long int n;
	scanf("%lld",&n);
	long long int i;
	long long int a[100005];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	long long int b[100005];
	for(i=0;i<n;i++)
		b[i]=a[(i+1)%n]-a[i];
	long long int sum=0;
	for(i=0;i<n;i++)
		sum+=a[i];
	if(sum%(n*(n+1)/2)>0)
	{
		printf("NO\n");
		return 0;
	}
	sum/=n*(n+1)/2;
	for(i=0;i<n;i++)
		b[i]=sum-b[i];
	long long int cnt=0;
	for(i=0;i<n;i++)
	{
		if(b[i]%n>0)
		{
			printf("NO\n");
			return 0;
		}
		if(b[i]<0)
		{
			printf("NO\n");
			return 0;
		}
		cnt+=b[i]/n;
	}
	if(cnt==sum)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

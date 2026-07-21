#include<stdio.h>
long long a[100010],b[100010];
int main()
{
	long long n,i,sum,t,t1,t2,p;
	while(scanf("%lld",&n)!=EOF)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum=sum+a[i];
		}
		t1=n*(n+1)/2;
		if(sum%t1!=0)
		{
			printf("NO\n");
			continue;
		}
		t2=sum/t1;
		for(i=1;i<n;i++)
		b[i]=a[i+1]-a[i];
		b[n]=a[1]-a[n];
		p=0;
		for(i=1;i<=n;i++)
		{
			t=t2-b[i];
			if(t<0)
			break;
			if(t%n!=0)
			break;
			p=p+t/n;
		}
		if(i!=n+1||p!=t2)
		printf("NO\n");
		else
		printf("YES\n");
	}
	return 0;
}

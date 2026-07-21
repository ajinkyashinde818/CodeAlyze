#include<stdio.h>
#include<math.h>
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	int a[100],b[100],c[100];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n-1;i++)scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
	{
		sum+=b[a[i]];
		if(i>=2)
		{
			if(a[i]-a[i-1]==1)
			{
				sum+=c[a[i-1]];
			}
			
		}
	}
	printf("%d",sum);
	return 0;
}

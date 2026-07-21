#include<stdio.h>
int main()
{
	int i,n,a[20],b[20],c[20],sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
	for(i=0;i<n-1;i++)
		scanf("%d",&c[i]);

	for(i=0;i<n;i++)
	{
		sum+=b[a[i]-1];
		if(i<n-1)
		{
		if((a[i+1]-a[i])==1)
			sum+=c[a[i]-1];
		}
	}
	printf("%d",sum);
	return 0;
}

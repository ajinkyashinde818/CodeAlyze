#include<stdio.h>

int main()
{
	int n,a[50],b[50],c[50],i,sum=0;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	{
	    scanf("%d",&b[i]);
	    sum+=b[i];
	}
	
	for(i=0;i<n-1;i++)
	scanf("%d",&c[i]);
	
	for(i=1;i<n;i++)
	{
		if(a[i]-a[i-1]==1)
		{
			sum+=c[a[i-1]-1];
		}
	}
	
	printf("%d\n",sum);
	
	return 0;
}

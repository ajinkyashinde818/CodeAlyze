#include<stdio.h>
#define N 200000
int main()
{
	int n;
	scanf("%d",&n);
	int a[N];
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	int min=a[0],max=a[1]-a[0];
	for(int i=1;i<n;i++)
	{
		if(min>=a[i-1])
		{
			min=a[i-1];
		}
		if(max<=(a[i]-min))
		{
			max=a[i]-min;
		}
	}
	printf("%d\n",max);
	return 0;
}

#include<stdio.h>
int main()
{
	int i,n,j;
	int max;
	int min;
	int maximum;
	int a[200000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	min=a[0];
	max=a[n-1];
	maximum=a[1]-a[0];

	for(i=n-2;i>=0;i--)
	{
		if(maximum<max-a[i])
			maximum=max-a[i];
	}

	for(i=n-2;i>1;i--)
	{
		if(a[i]>max)
		{
			max=a[i];
			for(j=i-1;j>=0;j--)
			{
				if(max-a[j]>maximum)
					maximum=max-a[j];
			}
		}
	}
	printf("%d\n",maximum);
	return 0;
}

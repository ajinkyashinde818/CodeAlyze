#include<stdio.h>
int main(void)
{	int i,n,mai=0,min,a[100000]={};
	unsigned long int sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	if(a[0]<0)
	{	a[0]*=-1;
		mai++;
	}
	min=a[0];
	sum+=a[0];
	for(i=1;i<n;i++)
	{	if(a[i]<0)
		{	a[i]*=-1;
			mai++;
		}
		sum+=a[i];
		if(a[i]<min)
			min=a[i];
	}
	if(mai%2==1)
		sum-=2*min;
	printf("%ld\n",sum);
	return 0;
}

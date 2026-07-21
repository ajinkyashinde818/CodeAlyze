#include<stdio.h>
long abs(long  a)
{
	if(a>0) return a;
	else return -a;
}
int main()
{
	long sum=0;
	int n,i;
	long min;
	long sumz=0,sumy=0;
	long x[200001];
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%ld",&x[i]);
		sum+=x[i];
	}
	sumy=sum;
	for(i=1;i<n;i++)
	{
		sumz+=x[i];
		sumy-=x[i];
		if(i==1) min=abs(sumz-sumy);
		else if(abs(sumz-sumy)<min) min=abs(sumz-sumy);
	}
	printf("%ld",min);
}

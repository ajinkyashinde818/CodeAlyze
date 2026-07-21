#include<stdio.h>
int main()
{
	int n,m,max;
	scanf("%d%d",&n,&m);
	int a[m+1],b[m+1];
	for(int i=0;i<m;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<m-1;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	b[m-1]=n-a[m-1]+a[0];
	max=b[0];
	for(int i=1;i<m;i++)
	{
		if(b[i]>max)
		max=b[i];
	}
	printf("%d\n",n-max);
	return 0;
}

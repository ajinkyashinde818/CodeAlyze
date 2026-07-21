#include <stdio.h>
int a[200010];
int max(int x,int y)
{
	return x>y?x:y;
}
int min(int x,int y)
{
	return x<y?x:y;
}
int main ()
{
	int i,j,n,maxf,minf;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		maxf=-2000000000;
		minf=a[0];
		for(i=1;i<n;i++)
		{
			maxf=max(maxf,a[i]-minf);
			minf=min(minf,a[i]);
		}
		printf("%d\n",maxf);
	}
	return 0;
}

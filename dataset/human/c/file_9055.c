#include <stdio.h>
int main ()
{
	int r=0,i,n,k,h[100100];
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(h[i]>=k)
		{
			r++;
		}
	}
	printf("%d",r);
	return 0;
}

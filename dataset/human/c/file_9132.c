#include<stdio.h>
int main()
{
	int n,k,i,y=0;

	scanf("%d%d",&n,&k);

	int h[n+1];

	for(i=0;i<n;i++)
		scanf("%d",&h[i]);
	for(i=0;i<n;i++)
		if(h[i]>=k)
			y++;
	printf("%d",y);
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[200010],b[200010];
int c[200010],d[200010];
int main(void)
{
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	memset(c,0,sizeof(c));
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]==1)
		c[b[i]]++;
		if(b[i]==1)
		c[a[i]]++;
		if(a[i]==n)
		d[b[i]]++;
		if(b[i]==n)
		d[a[i]]++;
		
	}
	k=0;
	for(i=2;i<n;i++)
	{
		if(c[i]==1&&d[i]==1)
		{
			k=1;
			break;
		}
	}
	if(k==1)
	printf("POSSIBLE\n");
	else
	printf("IMPOSSIBLE\n");
	return 0;
}

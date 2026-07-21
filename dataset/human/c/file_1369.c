#include<stdio.h>
int a[200005],b[200005],c[200005]={0},d[200005]={0};
int main()
{
	int n,m,i,k=0,j,t=0,o=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]==1)
			c[b[i]]++;
		if(b[i]==n)
			d[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		if(c[i]==1&&d[i]==1)
		{
			printf("POSSIBLE\n");
			return 0;
		}
		
	}
		printf("IMPOSSIBLE\n");
		return 0;
		
}

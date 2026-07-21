#include<stdio.h>
int main()
{
	int a[200001]={0};
	int n,m,x,y,i;
	scanf("%d%d",&n,&m);
	int flag=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		if(x==1&&y!=n)
		{
			a[y]++;
		}
		if(y==n&&x!=1)
		{
			a[x]++;
		}
		if(a[x]==2||a[y]==2)
		{
			flag=1;
		}
	}
	if(flag==1) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	return 0;
}

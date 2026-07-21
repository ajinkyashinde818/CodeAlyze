//https://atcoder.jp/contests/abc167/tasks/abc167_c
#include<stdio.h>
#define N 15
#define INF ((1<<30)-1)*2
short choose[N];
int a[N][N],cost[N],tot[N];
int main()
{
	register i;
	int n,m,x,j,ans=INF,cnt;
	scanf("%d%d%d",&n,&m,&x);
	for(i=1;i<=n;++i)
	{
		scanf("%d",cost+i);
		for(j=1;j<=m;++j)
			scanf("%d",a[i]+j);
	}
	do
	{
		cnt=0;
		for(i=1;i<=n;++i)
			tot[i]=0;
		
		for(i=1;i<=n;++i)
		{
			if(choose[i])
			{
				cnt+=cost[i];
				for(j=1;j<=m;++j)
					tot[j]+=a[i][j];
			}
		}
		for(i=1;i<=m;++i)
		{
			if(tot[i]<x)
			{
				cnt=INF;
				break;
			}
		}
		ans=ans<cnt?ans:cnt; 
		
		choose[n]=!choose[n];
		for(i=n-1;!choose[i+1];--i)
			choose[i]=!choose[i];
	}while(!choose[0]);
	
	printf("%d",ans==INF?-1:ans);
	return 0;
}

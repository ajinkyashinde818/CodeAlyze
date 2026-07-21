#include<stdio.h>
#include<string.h>
char a[55][55],b[55][55];
int n,m;
int find(int x,int y)
{
	int i1,i2,j1,j2;
	for(i1=x,i2=0;i2<m;i2++,i1++)
	for(j1=y,j2=0;j2<m;j2++,j1++)
	if(a[i1][j1]!=b[i2][j2])
	return 0;
	return 1;
}
int main()
{
	int i,j,k,t;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%s",a[i]);
		for(i=0;i<m;i++)
		scanf("%s",b[i]);
		k=0;
		for(i=0;i<=n-m;i++)
		for(j=0;j<=n-m;j++)
		if(a[i][j]==b[0][0])
		{
			t=find(i,j);
			if(t==1)
			k=1;
		}
		if(k==1)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
}

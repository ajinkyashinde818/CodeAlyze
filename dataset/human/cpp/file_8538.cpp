#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char a[51][51],b[51][51];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=getchar();
			while(a[i][j]!='#' && a[i][j]!='.')a[i][j]=getchar();
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			b[i][j]=getchar();
			while(b[i][j]!='#' && b[i][j]!='.')b[i][j]=getchar();
		}
	}
	for(int i=1;i<=n-m+1;i++)
	{
		for(int j=1;j<=n-m+1;j++)
		{
			bool f=true;
			for(int k=i;k<i+m;k++)
			{
				for(int l=j;l<j+m;l++)
				{
					if(a[k][l]!=b[k-i+1][l-j+1])
					{
						f=false;
						break;
					}
				}
				if(!f)break;
			}
			if(f)
			{
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}

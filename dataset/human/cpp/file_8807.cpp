#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n,m;
	char a[55][55];
	char b[55][55];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
		scanf("%s",a[i]+1);
		for(int i=1;i<=m;i++)
		scanf("%s",b[i]+1);
		int flag=0;
		for(int e=1;e<=n-m+1;e++)
		for(int i=1;i<=n-m+1;i++)
		{
			int cnt=0;
			for(int j=1;j<=m;j++)
			for(int k=1;k<=m;k++)
			{
				if(b[j][k]==a[e+j-1][i+k-1])
				cnt++;
			}
			if(cnt==m*m)
			flag=1;
		}
		if(flag)
		printf("Yes\n");
		else
		printf("No\n");
	}
	return 0;
 }

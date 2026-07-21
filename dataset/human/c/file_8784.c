#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
int main()
{
	int m,n;
	char a[55][55];
	while(~scanf("%d%d",&m,&n))
	{
		int flag=1;
		memset(a,'.',sizeof(a));
		for(int i=1;i<=m;i++)
	    {
			getchar();
			for(int j=1;j<=n;j++)
			scanf("%c",&a[i][j]);
		}
		for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		if(a[i][j]=='#')
		{
			if(a[i-1][j]=='.'&&a[i+1][j]=='.'&&a[i][j-1]=='.'&&a[i][j+1]=='.')
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		printf("No\n");
		else
		printf("Yes\n");
	}
}

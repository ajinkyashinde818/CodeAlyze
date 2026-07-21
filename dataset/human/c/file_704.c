#include<stdio.h>
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char a[55][55],b[55][55];
	int i,j;
	int k;
	for(i=0;i<n;i++)
	  scanf("%s",a[i]);
	for(i=0;i<m;i++)
	  scanf("%s",b[i]);
	int x,y;
	for(x=0;x<=n-m;x++)
	{
		for(y=0;y<=n-m;y++)
		{
			k=0;
			for(i=0;i<m;i++)
			{
				for(j=0;j<m;j++)
				{
					if(b[i][j]!=a[x+i][y+j])
					{
						k++;
						break;
					}
				}
				if(k>0)
				  break;
			}
			if(k==0)
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}

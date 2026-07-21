#include<stdio.h>
int main(void)
{
	int n,m,x,y,c=0,i,j,k,l;
	char a[50][50],b[50][50];
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
	scanf("%s", &a[i]);
	for(i=0; i<m; i++)
	scanf("%s", &b[i]);
	for(i=0; i<n-m+1; i++)
	{
		for(j=0; j<n-m+1; j++)
		{
			if(a[i][j]==b[0][0])
			{
				x=0;
				for(k=i; k<i+m; k++)
				{
					y=0;
					for(l=j; l<j+m; l++)
					{
						if(a[k][l]!=b[x][y])
						break;
						y++;
					}
					if(y<m)
					break;
					x++;
				}
				if(x==m)
				c=1;
			}
		}
	}
	if(c>0)
	printf("Yes\n");
	else
	printf("No\n");
	
	return 0;
}

#include<stdio.h>
#include<string.h>
char a[51][51],b[51][51];
int main()
{
	int i,j,k,l,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	scanf("%s",&a[i]);
	for(j=0;j<m;j++)
	scanf("%s",&b[j]);
	for(k=0;k<n;k++)
	for(l=0;l<n;l++)
	{
		if(a[k][l]==b[0][0])
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[k+i][l+j]!=b[i][j])
				break;
			}
			if(j!=m)
			break;
			
		}
		if(i==m)
		{
			printf("Yes");
			return 0;
		}
			
	}
	printf("No");
	return 0;
	
}

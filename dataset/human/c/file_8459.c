#include<stdio.h>
int main(void)
{
	int n,m,z[100],t,i,j;
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
	scanf("%d", &z[i]);
	for(i=1; i<=m; i++)
	{
		for(j=0; j<n-1; j++)
		{
			if(z[j]%i>z[j+1]%i)
			{
				t=z[j];
				z[j]=z[j+1];
				z[j+1]=t;
			}
		}
	}
	for(i=0; i<n; i++)
	printf("%d\n", z[i]);
	
	return 0;
}

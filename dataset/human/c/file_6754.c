#include<stdio.h>
int main(void)
{
	int n,m,a[10000],b[10000],x[501],i;
	while(1)
	{
		scanf("%d %d", &n, &m);
		if(n==0)
		break;
		for(i=0; i<m; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			if(a[i]==1)
			x[b[i]]=1;
		}
		for(i=0; i<m; i++)
		{
			if(x[a[i]]==1&&x[b[i]]<1)
			x[b[i]]=2;
			if(x[b[i]]==1&&x[a[i]]<1)
			x[a[i]]=2;
		}
		m=0;
		for(i=2; i<=n; i++)
		{
			if(x[i]>0)
			{
				m++;
				x[i]=0;
			}
		}
		printf("%d\n", m);
	}
	
	return 0;
}

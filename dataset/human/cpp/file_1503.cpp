#include <bits/stdc++.h>
using namespace std;

int n,pd,a[2010][2010],ji;
int main()
{
	scanf("%d",&n);
	for(int i=1;i*(i-1)<=2*n;++i)
	{
		if(i*(i-1)==2*n)
		{
			pd=i;
			break;
		}
	}
	if(pd==0)
	printf("No\n");
	else
	{
		printf("Yes\n");
		printf("%d\n",pd);
		for(int i=1;i<=pd-1;++i)
		a[1][i]=i;
		ji=pd-1;
		for(int i=2;i<=pd;++i)
		{
			for(int j=1;j<i;++j)
			a[i][j]=a[j][i-1];
			for(int j=i;j<=pd-1;++j)
			a[i][j]=++ji;
		}
		for(int i=1;i<=pd;++i)
		{
			printf("%d ",pd-1);
			for(int j=1;j<=pd-1;++j)
			printf("%d ",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}

#include<stdio.h>
int a[100020];
int main ()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,k=0,m,t=0;
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		i=0;
		while(a[i]!=2)
		{
			if(a[i]==0)
			{
				printf("-1\n");
				t++;
				break;
			}
			m=i;
			i=a[i]-1;
			a[m]=0;
			k++;
		}
		if(t==0)
			printf("%d\n",k+1);
	}
}

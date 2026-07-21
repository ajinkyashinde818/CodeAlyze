#include<stdio.h>
#include<math.h>
#include<string.h>
int a[200005];
int b[200005];
int num[200005]={0};
int sum[200005]={0};
int main ()
{
	int n,m,i,j,s=0,d=0,g=0; 
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(a[i]==1)
			num[b[i]]++;
		if(b[i]==n)
		    sum[a[i]]++;
	}
		for(i=1;i<n;i++)
		{
			if(num[i]>=1&&sum[i]>=1)
			{
				printf("POSSIBLE\n");
				return 0;
			}
		}
		printf("IMPOSSIBLE\n");
	return 0;
}

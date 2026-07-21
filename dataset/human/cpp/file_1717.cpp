#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int val[1005][1005];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	int B=0;
	for(i=1;i<=1000;i++)
		if(i*(i-1)/2==n)
		{
			B=i;
			break;
		}
	if(B==0)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	printf("%d\n",B);
	int cntz=0;
	memset(val,0,sizeof(val));
	for(i=1;i<=B;i++)
	{
		for(j=1;j<=B-1;j++)
			if(val[i][j]==0)
			{
				cntz++;
				val[i][j]=cntz;
			}
		printf("%d ",B-1);
		for(j=i+1;j<=B;j++)
			val[j][i]=val[i][j-1];
		for(j=1;j<B;j++)printf("%d ",val[i][j]);
		printf("\n");
	}
}

#include<cstdio>
#include<cstdlib>
#include<vector>
using namespace std;
const int N=100100;
vector<int>g[N];
int main()
{
	int n,k=0;
	int cnt=1;
	scanf("%d",&n);
	if(n==1)return printf("Yes\n2\n1 1\n1 1"),0;
	for(int i=1;i<=n;i++)
	{
		if(i*(i-1)/2==n)
		{
			k=i;
			break;
		}
	}
	if(k==0)return printf("No\n"),0;
	printf("Yes\n%d\n",k);
	for(int i=1;i<=k;i++)
	{
		if(cnt>n)break;
		for(int j=i+1;j<=k;j++)
		{
			if(cnt>n)break;
			g[i].push_back(cnt);
			g[j].push_back(cnt);
			cnt++;
		}
	}
	for(int i=1;i<=k;i++)
	{
		printf("%d ",g[i].size());
		for(int j=0;j<g[i].size();j++)
			printf("%d ",g[i][j]);
		printf("\n");
	}
	return 0;
}

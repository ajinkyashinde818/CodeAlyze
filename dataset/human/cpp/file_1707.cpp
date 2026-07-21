#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v[606];
int main()
{
	int n,now=1,ans=2,cnt;
	scanf("%d",&n);
	while(now<n)
	{
		now+=ans;
		ans++;
	}
	if(now!=n)
	{
		printf("No");
		return 0;
	}
	cnt=0;
	for(int i=1;i<ans;i++)
		for(int j=i+1;j<=ans;j++)
		{
			++cnt;
			v[i].push_back(cnt);
			v[j].push_back(cnt);
		}
	printf("Yes\n%d\n",ans);
	for(int i=1;i<=ans;i++)
	{
		printf("%d",(int)v[i].size());
		for(int j=0;j<v[i].size();j++)
			printf(" %d",v[i][j]);
		printf("\n");
	}
	return 0;
}

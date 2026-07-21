#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=100005;
int n;
vector<int> vec[N];
int main()
{
	scanf("%d",&n);
	if (n==1)
	{
		printf("Yes\n");
		printf("2\n");
		printf("1 1\n");
		printf("1 1\n");
		return 0;
	}
	if (n==2)
	{
		printf("No\n");
		return 0;
	}
	int now=3;
	vec[1].push_back(1);
	vec[1].push_back(3);
	vec[2].push_back(1);
	vec[2].push_back(2);
	vec[3].push_back(2);
	vec[3].push_back(3);
	int lalal=3;
	while (now<n)
	{
		lalal++;
		for (int i=1;i<lalal;i++)
		{
			now++;
			vec[i].push_back(now);
			vec[lalal].push_back(now);
			if (now>n)
			{
				printf("No\n");
				return 0;
			}
		}
		if (now>n)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	printf("%d\n",lalal);
	for (int u=1;u<=lalal;u++)
	{
		int siz=vec[u].size();
		printf("%d ",siz);
		for (int i=0;i<siz;i++) printf("%d ",vec[u][i]);
		printf("\n");
	}
	return 0;
}

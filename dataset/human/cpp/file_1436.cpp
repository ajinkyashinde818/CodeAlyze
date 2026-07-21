#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> v[1010];
int main()
{
	cin>>n;
	int k=1;
	while (1LL*k*(k-1)/2<n)
	{
		k++;
	}
	if (1LL*k*(k-1)/2!=n)
	{
		puts("No");
		return 0;
	}
	for (int i=1,cnt=1;i<k;i++)
	{
		for (int j=i+1;j<=k;j++)
		{
			v[i].push_back(cnt);
			v[j].push_back(cnt);
			cnt++;
		}
	}
	printf("Yes\n%d\n",k);
	for (int i=1;i<=k;i++)
	{
		printf("%d ",v[i].size());
		for (int j=0;j<v[i].size();j++)
		{
			printf("%d ",v[i][j]);
		}
		puts("");
	}
	return 0;
}

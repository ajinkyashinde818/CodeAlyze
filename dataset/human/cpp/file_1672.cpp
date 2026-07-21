#include<bits/stdc++.h>
using namespace std;
int n,maxa,vis[100005];
vector<int> v[505];
int main()
{
	int sum=1;vis[1]=2;
	for(int i=2;i;i++){if(sum+i>100000) break;sum+=i;vis[sum]=i+1;maxa=max(maxa,vis[sum]);}
	cin>>n;if(!vis[n]) return !puts("No");int m=1,gg=0;
	while(gg<n){for(int i=1;i<=m;i++) v[i].push_back(i+gg);for(int i=1;i<=m;i++) v[m+1].push_back(i+gg);gg+=m;m++;}
	puts("Yes");cout<<vis[n]<<endl;
	for(int i=1;i<=vis[n];i++)
	{
		printf("%d",v[i].size());
		for(int j=0;j<v[i].size();j++) printf(" %d",v[i][j]);puts("");
	}
}

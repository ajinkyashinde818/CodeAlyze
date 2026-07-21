#include<bits/stdc++.h>
using namespace std;
int n,t[4],ans,able[3010][4];
bool dfs(int total,int id)
{
	if(able[total][id]==1)
	{
		ans++;
		return true;
	}
	if(total==n)
	{
		ans++;
		return true;
	}
	if(id>3||total+t[id]>n)
		return false;
	int flag=0;
	for(int i=0;(i+1);i++)
	{
		if(t[id]*i+total<=n)
		{
			if(dfs(t[id]*i+total,id+1))
			{
				flag=1;
				able[total][id]=1;
			}
		}else
			break;
	}
	if(flag)
		return true;
	else
		return false;
}
int main()
{
	cin>>t[1]>>t[2]>>t[3]>>n;
	sort(t+1,t+4);
	dfs(0,1);
	cout<<ans;
	return 0;
}

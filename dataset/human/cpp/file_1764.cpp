#include "bits/stdc++.h"

using namespace std;

int main()
{
	deque<int> que;
	bool num[200001];
	fill(num,num+200001,false);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n+1;i++)
		que.push_back(i);
	for(int i=0;i<m;i++)
	{
		int e;
		cin>>e;
		que.push_front(e);
	}

	while(!que.empty())
	{
		int t=que[0];
		que.pop_front();
		if(!num[t])
		{
			cout<<t<<endl;
			num[t]=true;
		}
	}
	return 0;
}

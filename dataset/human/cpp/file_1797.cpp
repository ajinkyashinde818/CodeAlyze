#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<set>
#include<queue>

using namespace std;

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> head(m);
	vector<bool> used(n,false);

	for(int i=0;i<m;i++)
		cin >> head[i];

	for(int i=m-1;i>=0;i--)
		if(used[head[i]-1]!=true)
		{
			cout << head[i] << endl;
			used[head[i]-1]=true;
		}
	for(int i=1;i<=n;i++)
	{
		if(used[i-1]!=true)
			cout << i << endl;
	}

	




}

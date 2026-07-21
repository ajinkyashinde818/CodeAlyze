#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	int n,m;
	char a[55][55],b[55][55];
	bool flag=true;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>b[i][j];
		}
	}
	for(int i=0;i<=n-m;i++)
	{
		for(int j=0;j<=n-m;j++)
		{
			flag=true;
			for(int k=i;k<i+m;k++)
			{
				for(int l=j;l<j+m;l++)
				{
					if(a[k][l]!=b[k-i][l-j])flag=false;
				}
			}
			if(flag)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}

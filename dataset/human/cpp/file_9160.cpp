#include<iostream>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int main()
{
	char a[55][55],b[55][55];
	int f,n,m;cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)cin>>b[i][j];
	for(int k=0;k<=n-m;k++)
	{
		for(int l=0;l<=n-m;l++)
		{
			f=0;
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(a[i+k][j+l]!=b[i][j])
					{
						f=1;
						break;
					}
				}
				if(f==1)break;
			}
			if(f==0)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}

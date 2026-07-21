#include<algorithm>
#include<bitset>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<memory> 
using namespace std;

int n,m;
string a[55],b[55];

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	bool flag;
	for(int i=0;i<=n-m;i++)
	{
		for(int j=0;j<=n-m;j++)
		{
			flag=true;
			for(int ii=0;ii<m;ii++)
			{
				for(int jj=0;jj<m;jj++)
				{
					if(a[i+ii][j+jj]!=b[ii][jj])
					{
						flag=false;
					}
				}
			}
			if(flag==true)
			{
				cout<<"Yes"<<endl;
				return 0;
			}
		}
	} 
	cout<<"No"<<endl;
	return 0;
}

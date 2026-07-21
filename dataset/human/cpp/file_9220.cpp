#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<string.h>
#include<math.h>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<vector>
#include<functional>
#include<algorithm>
#include<assert.h>
#include<numeric>
#include<limits.h>
using namespace std;
int n,m;
int a[55][55],b[55][55];
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
	{
		char c;
		cin>>c;
		if(c=='.')a[i][j]=1;else a[i][j]=0;
	}
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)
	{
		char c;
		cin>>c;
		if(c=='.')b[i][j]=1;else b[i][j]=0;
	}
	if(n<m)
	{
		printf("No\n");
		return 0;
	}
	for(int i=0;i<n-m+1;i++)
	{
		for(int j=0;j<n-m+1;j++)
		{
			bool f=true;
			for(int k=0;k<m;k++)
			{
				for(int l=0;l<m;l++)
				{
					if(a[i+k][j+l]!=b[k][l])
					{
						f=false;
					}
				}
			}
			if(f==true)
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}

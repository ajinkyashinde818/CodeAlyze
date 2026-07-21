#include <cstdio>
#include <iostream>
using namespace std;

char N[55][55],M[55][55];

bool same(int row,int col,int m)
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			if(M[i][j]!=N[i+row-1][j+col-1])
				return 0;
	return 1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>N[i][j];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++)
			cin>>M[i][j];

	for(int i=1;i<=n-m+1;i++)
		for(int j=1;j<=n-m+1;j++)
			if(same(i,j,m))
			{
				printf("Yes\n");
				return 0;
			}

	printf("No\n");
}
